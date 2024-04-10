#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,res;
pii ans={1,2};
map<int,pii>f;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,L=0;scanf("%d",&a);
		f[a]={0,i};
	}
	int x=2e9;
	for(;;){
		auto it=--f.lower_bound(x);
		x=it->fi;
		if(x==0)break;
		int fa;
		for(int i=0;i<31;i++)if((1<<i)>=x){fa=(1<<i)-x;break;}
		pii y=it->se;
		if(f.find(fa)==f.end())f[fa]={-1e9,0};
		pii F=f[fa];
		if(res<y.fi+F.fi+1){
			res=y.fi+F.fi+1;
			ans={y.se,F.se};
		}
		f[fa]=max(f[fa],{y.fi+1,y.se});
	}
	printf("%d %d %d",ans.fi,ans.se,res);
}