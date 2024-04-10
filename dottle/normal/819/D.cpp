#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

int t,n,s,g;
int a[N],b[N],res[N];

void exgcd(int a,int b,int&x,int&y){
	if(b)exgcd(b,a%b,y,x),y-=a/b*x;
	else x=1,y=0;
}int inv(int k,int mod){
	int x,y;
	exgcd(k,mod,x,y);
	return (x%mod+mod)%mod;
}

map<int,int> vis;
map<int,vector<int>> A;

void solve(vector<int> pos){
	for(auto x:pos)
		b[x]=(a[x]%t/g)*inv(s/g,t/g)%(t/g);
	sort(pos.begin(),pos.end(),[](int x,int y){return b[x]<b[y];});
	int sz=pos.size();
	for(int t=0;t+1<sz;t++){
		int x=pos[t],y=pos[t+1];
		res[x]=(b[y]-b[x]);
	}
	res[pos[sz-1]]=(t/g+b[pos[0]]-b[pos[sz-1]]);
}

void solve(){
	cin>>t>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]+=a[i-1];
	s=a[n];
	g=__gcd(s,t);
	for(int i=1;i<=n;i++)
		if(!vis[a[i]%t]){
			A[a[i]%g].push_back(i);
			vis[a[i]%t]=1;
		}
	for(auto x:A)solve(x.second);
	for(int i=1;i<=n;i++)
		cout<<res[i]<<' ';
}

main(){
	ios::sync_with_stdio(0);
	solve();
}