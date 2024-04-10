#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
#define I inline
I void Swap(int&x,int&y){
	int t=x;
	x=y;
	y=t;
}
struct Edge{
	int Start,End,Len,Id;
	I void Read(){
		scanf("%d%d%d",&Start,&End,&Len);
	}
	I friend bool operator<(Edge A,Edge B){
		return A.Len<B.Len;
	}
}e[300000];
int ans[300000];
vector<int>E[999999];
I void Cover(int p,int lf,int rt,const int l,const int r,const int d){
	if(l<=lf&&rt<=r){
		E[p].push_back(d);
	}else{
		int mid=lf+rt>>1;
		if(l<=mid){
			Cover(p<<1,lf,mid,l,r,d);
		}
		if(r>mid){
			Cover(p<<1|1,mid+1,rt,l,r,d);
		}
	}
}
class DisjiontSet{
	int f[100001],sz[100001],tot;
	I int GetF(int x){
		while(x!=f[x]){
			x=f[x];
		}
		return x;
	}
	public:
		I void Init(const int n){
			for(R i=1;i<=n;i++){
				sz[i]=1;
				f[i]=i;
			}
			tot=n;
		}
		I int Merge(int x,int y){
			x=GetF(x);
			y=GetF(y);
			if(x==y){
				return 0;
			}
			tot+=((sz[x]^sz[y])&1)-(sz[x]&1)-(sz[y]&1);
			if(sz[x]<sz[y]){
				Swap(x,y);
			}
			f[y]=x;
			sz[x]+=sz[y];
			return y;
		}
		I void Seperate(int x){
			sz[f[x]]-=sz[x];
			tot+=(sz[f[x]]&1)+(sz[x]&1)-((sz[x]^sz[f[x]])&1);
			f[x]=x;
		}
		I bool Check(){
			return tot==0;
		}
}S;
I void Solve(int p,int lf,int rt,int&pos,const int m){
	vector<int>D;
	for(vector<int>::iterator T=E[p].begin();T!=E[p].end();T++){
		int x=S.Merge(e[*T].Start,e[*T].End);
		if(x!=0){
			D.push_back(x);
		}
	}
	if(lf==rt){
		while(pos!=m&&S.Check()==false){
			if(e[pos].Id<=rt){
				int x=S.Merge(e[pos].Start,e[pos].End);
				if(x!=0){
					D.push_back(x);
				}
				if(e[pos].Id!=lf){
					Cover(1,0,m-1,e[pos].Id,lf-1,pos);
				}
			}
			pos++;
		}
		if(S.Check()==true){
			ans[lf]=e[pos-1].Len;
		}else{
			ans[rt]=-1;
		}
	}else{
		Solve(p<<1|1,lf+rt+2>>1,rt,pos,m);
		Solve(p<<1,lf,lf+rt>>1,pos,m);
	}
	for(vector<int>::reverse_iterator T=D.rbegin();T!=D.rend();T++){
		S.Seperate(*T);
	}
}
int main(){
	int n,m,p=0;
	scanf("%d%d",&n,&m);
	S.Init(n);
	for(R i=0;i!=m;i++){
		e[i].Read();
		e[i].Id=i;
	}
	sort(e,e+m);
	Solve(1,0,m-1,p,m);
	for(R i=0;i!=m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}