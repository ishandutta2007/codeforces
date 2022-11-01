#include<stdio.h>
#include<set>
using namespace std;
#define I inline
#define N 800000
I void Min(int&x,const int y){
	if(x>y){
		x=y;
	}
}
int MinR[N];
I void Init(int p,int lf,int rt){
	MinR[p]=N;
	if(lf!=rt){
		Init(p<<1,lf,lf+rt>>1);
		Init(p<<1|1,lf+rt+2>>1,rt);
	}
}
I void Modify(int p,int lf,int rt,const int x,const int d){
	Min(MinR[p],d);
	if(lf!=rt){
		int mid=lf+rt>>1;
		if(x>mid){
			Modify(p<<1|1,mid+1,rt,x,d);
		}else{
			Modify(p<<1,lf,mid,x,d);
		}
	}
}
I int GetMin(int p,int lf,int rt,const int l,const int r){
	if(l<=lf&&rt<=r){
		return MinR[p];
	}
	int mid=lf+rt>>1,res=N;
	if(l<=mid){
		res=GetMin(p<<1,lf,mid,l,r);
	}
	if(r>mid){
		Min(res,GetMin(p<<1|1,mid+1,rt,l,r));
	}
	return res;
}
int main(){
	int n,q,opt,l,r,x;
	scanf("%d%d",&n,&q);
	Init(1,1,n);
	set<int>S;
	for(int i=1;i<=n;i++){
		S.insert(i);
	}
	for(register int i=0;i!=q;i++){
		scanf("%d%d",&opt,&l);
		if(opt==0){
			scanf("%d%d",&r,&x);
			if(x==0){
				for(auto T=S.lower_bound(l);T!=S.end()&&*T<=r;T=S.lower_bound(l)){
					S.erase(T);
				}
			}else{
				Modify(1,1,n,l,r);
			}
		}else if(S.count(l)==0){
			puts("NO");
		}else{
			auto T=S.lower_bound(l);
			if(T==S.begin()){
				x=1;
			}else{
				x=*prev(T)+1;
			}
			T=next(T);
			if(T==S.end()){
				r=N;
			}else{
				r=*T;
			}
			if(GetMin(1,1,n,x,l)<r){
				puts("YES");
			}else{
				puts("N/A");
			}
		}
	}
	return 0;
}