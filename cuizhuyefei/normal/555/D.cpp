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
const int N = 233333;
map<int,int> Map;
int n,s[N],v[N];
int Ri(int pos, int len) {
	return s[upper_bound(s+1,s+n+1,pos+len)-s-1];
}
int Le(int pos, int len) {
	return *lower_bound(s+1,s+n+1,pos-len);
}
int abs(int x) {return x>0?x:-x;}
int f(int pos, int len) {
	int x=Ri(pos,len),y=Le(x,len-(x-pos));
	if (x==pos&&y==pos) return pos;
	if (y==pos) {
		len%=2*(x-pos); return f(pos,len);
	}
	return f(y,len-abs(x-pos)-abs(x-y));
//	int p=upper_bound(s+1,s+n+1,pos)-s;	
}

int main() {
	read(n); int m; read(m);
	rep(i,1,n) read(s[i]),v[i]=s[i],Map[s[i]]=i;
	sort(s+1,s+n+1);
	while (m--) {
		int p,l; read(p); read(l);
		printf("%d\n",Map[f(v[p],l)]);
	}
	return 0;
}