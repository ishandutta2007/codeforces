#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int mo = 1000000009;
int n;
ll ans,f[1000005];
int main() {
	read(n);
	f[1]=5;rep(i,2,n)f[i]=(3+2*f[i-1])%mo; ll now=1;
	for(int i=2;i<=n;i++) {
		if (i>=5&&(i&1)) now=now*f[(i-3)/2]%mo;ans+=2*now;
	}
	ans%=mo;ans=ans*ans%mo;ans++;ans*=2;ans%=mo;cout<<ans;
	return 0;
}