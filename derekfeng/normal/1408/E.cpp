#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
int n,m,a[100004],b[100004];
vector<pair<int,pii> >v;
int f[200004];
long long ans=0,ret=0;
int F(int x){
	return f[x]==x?x:f[x]=F(f[x]);
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n+m;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int s;scanf("%d",&s);while(s--){
			int x;scanf("%d",&x);
			v.push_back(mkp(b[x]+a[i],mkp(i+n,x))); 
			ans+=b[x]+a[i];
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
		int A=v[i].se.fi,B=v[i].se.se;
		if(F(A)!=F(B)){
			ret+=v[i].fi;
			f[f[A]]=B;
		}
	}
	cout<<ans-ret;
}