#include<stdio.h>
#include<queue>
using namespace std;
#define R register int
#define I inline
struct Emp{
	int l,r;
}p[200001];
I bool Com(Emp x,Emp y){
	if(x.l==y.l){
		return x.r>y.r;
	}
	return x.l>y.l;
}
int n;
long long s;
I int Min(int &x,int &y){
	return x<y?x:y;
}
I int Max(int &x,int &y){
	return x>y?x:y;
}
I bool Check(int x){
	priority_queue<int>Q;
	int ct=0;
	long long tot=0;
	for(R i=0;i<n;i++){
		if(p[i].r<x){
			tot+=p[i].l;
		}else{
			if(p[i].l>x){
				tot+=p[i].l;
				ct++;
			}else{
				Q.push(p[i].l);
			}
		}
	}
	while(ct<=(n>>1)&&Q.empty()==false){
		ct++;
		tot+=x;
		Q.pop();
	}
	while(Q.empty()==false){
		tot+=Q.top();
		Q.pop();
	}
	if(tot>s||ct<=(n>>1)){
		return false;
	}
	return true;
}
I void Solve(){
	int lf=2e9,ans,rt=0,mid;
	scanf("%d",&n);
	scanf("%lld",&s);
	for(R i=0;i<n;i++){
		scanf("%d%d",&p[i].l,&p[i].r);
		lf=Min(lf,p[i].l);
		rt=Max(rt,p[i].r);
	}
	ans=lf;
	while(lf<=rt){
		mid=lf+rt>>1;
		if(Check(mid)==true){
			ans=mid;
			lf=mid+1;
		}else{
			rt=mid-1;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}