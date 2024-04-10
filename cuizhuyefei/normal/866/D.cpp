#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> Pll;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
int n,x;
priority_queue<Pll,vector<Pll>,greater<Pll> > heap;
int main() {
	read(n); ll ans=0;
	rep(i,1,n) {
		read(x);
		if (!heap.empty()&&x>heap.top().fi) {
			Pll u=heap.top(); ans+=x-u.fi; heap.pop(); 
			heap.push(Pll(x,1)); if (u.se) heap.push(Pll(u.fi,0));
		}
		else heap.push(Pll(x,0));
	}
	cout<<ans;
	return 0;
}