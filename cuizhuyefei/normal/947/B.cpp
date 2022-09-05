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
const int N = 200000;
int n,v[N],t[N];
priority_queue<ll,vector<ll>,greater<ll> > heap;
int main() {
	read(n); rep(i,1,n) read(v[i]); rep(i,1,n) read(t[i]);
	ll ans=0,dd=0;
	rep(i,1,n) {
		heap.push(v[i]+dd); ans=0;
		while (!heap.empty()&&heap.top()-dd<=t[i]) {
			ans+=heap.top()-dd; heap.pop();
		}
		ans+=1LL*heap.size()*t[i]; dd+=t[i];
		cout<<ans<<' ';
	}
	return 0;
}