#include<bits/stdc++.h>
#define int long long
#define ls k<<1
#define rs k<<1|1
#define mid ((l+r)>>1)
const int N=100005,M=2005,P=32,X=1e7+19,Y=1e9+7;
using namespace std;

int w[N],v[N],s[N],t[N];
vector<pair<int,int>> q[N]; 
int f[P][M],x[N];
int n,m,o,cnt;

void push(int k,int l,int r,int x,int y,pair<int,int>u){
	if(r<x||l>y)return ;
	if(r<=y&&l>=x){
		q[k].push_back(u);return;
	}
	push(ls,l,mid,x,y,u),push(rs,mid+1,r,x,y,u);
}
void solve(int k,int l,int r,int d){
	memcpy(f[d],f[d-1],sizeof(f[d]));
	for(auto x:q[k])
		for(int i=m;i>=x.second;i--)
			f[d][i]=max(f[d][i],f[d][i-x.second]+x.first);
	if(l==r){
		if(x[l]){
			int ans=0;
			for(int i=1,j=1;i<=m;i++,j=j*X%Y)
				ans+=f[d][i]*j%Y;
			cout<<ans%Y<<endl;
		}
	}else solve(ls,l,mid,d+1),solve(rs,mid+1,r,d+1);
}

void solve(){
	cin>>n>>m;cnt=n;
	for(int i=1;i<=n;i++)cin>>v[i]>>w[i],s[i]=1;
	cin>>o;
	for(int i=1;i<=o;i++){
		int a,b;cin>>a;
		if(a==1){
			++cnt;cin>>v[cnt]>>w[cnt],s[cnt]=i; 
		}else if(a==2){
			cin>>b;t[b]=i;
		}else x[i]=1;
	}
	for(int i=1;i<=cnt;i++)
		push(1,1,o,s[i],t[i]?t[i]:o,{v[i],w[i]});
	solve(1,1,o,1);
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}