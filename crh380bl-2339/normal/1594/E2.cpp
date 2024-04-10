#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inv3 333333336
#define inv6 166666668
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int f[62];
map<string,int>M;
map<ll,int>col,g[7];
set<ll>S;
bool can(int x,int y){
	return abs(x-y)!=3&&x!=y;
}
int DFS(ll x,int c){
	int i,j;
	if(!S.count(x)){
		for(i=1;i<=6;++i){
			g[i][x]=1LL*f[c]*inv6%mod;
		}
		return f[c];
	}
	if(c==1){
		assert(col[x]);
		return g[col[x]][x]=1;
	}
	DFS(x<<1,c-1);
	DFS(x<<1|1,c-1);
	int s1=0,s2=0,ans=0;
	for(i=1;i<=6;++i){
		s1=s2=0;
		for(j=1;j<=6;++j)if(can(i,j))s1=(s1+g[j][x<<1])%mod;
		for(j=1;j<=6;++j)if(can(i,j))s2=(s2+g[j][x<<1|1])%mod;
		if(!col[x]||i==col[x]){
			g[i][x]=1LL*s1*s2%mod;
		}
		else g[i][x]=0;
		ans=(ans+g[i][x])%mod;
	}
	return ans;
}
int main(){
	int n,i,k;f[1]=6;
	ll x;
	string s;
	read(n);
	for(i=2;i<=n;++i)f[i]=1LL*f[i-1]*f[i-1]%mod*8%mod*inv3%mod;
	M["white"]=1;
	M["yellow"]=4;
	M["red"]=2;
	M["orange"]=5;
	M["green"]=3;
	M["blue"]=6;
	read(k);
	for(i=1;i<=k;++i){
		read(x);
		cin>>s;
		col[x]=M[s];
		while(x){
			if(!S.count(x))S.insert(x);
			x>>=1;
		}
	}
	cout<<DFS(1,n)<<endl;
	return 0;
}