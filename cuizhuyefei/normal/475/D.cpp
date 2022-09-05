#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 202000;
map<int,ll> ans;
map<int,int> s,t;
int n,a[N];
inline int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
int main() {
	read(n); rep(i,1,n) read(a[i]);
	rep(i,1,n) {
		t.clear(); while (!s.empty()) {
			Pii u=*s.begin(); s.erase(s.begin());
			t[gcd(a[i],u.fi)]+=u.se;
		}
		s=t; s[a[i]]++;
		for (map<int,int>::iterator it=s.begin(); it!=s.end(); it++) ans[(*it).fi]+=(*it).se;
	}
	int q; read(q); while (q--) {
		int x; read(x); printf("%lld\n",ans[x]);
	}
	return 0;
}