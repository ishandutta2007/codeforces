#include <iostream>
#include <cstdio>
#include <map>
#define int long long
#define mod 1000000007
using namespace std;
inline int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
map <int,int>f;
int n,m;
inline int dfs(int x,int y){
	if (x%y!=0)return 0;
	x/=y,y=1;
	if (f[x]!=0)return f[x];
	int s=Qpow(2,x-1);
	for (int i=1;i*i<=x;i++){
		if (x%i!=0)continue;
		if (i!=1)s-=dfs(x,i);
		if (i!=x/i&&x/i!=1)s-=dfs(x,x/i);
		s=(s%mod+mod)%mod; 
	}
	return f[x]=s;
}
signed main(){
	cin>>m>>n;
	cout<<dfs(n,m)<<endl;
	return 0;
}