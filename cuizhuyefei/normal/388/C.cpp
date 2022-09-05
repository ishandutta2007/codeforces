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
const int N = 600050;
int n,ans1,ans2;
int s[N],len,a[N];
bool cmp(int a, int b) {return a>b;}
int main() {
	read(n);
	rep(i,1,n) {
		int l; read(l); rep(j,1,l) read(a[j]);
		if (l&1) {
			s[++len]=a[l/2+1]; 
			rep(j,1,l)
				if (j<l/2+1) ans1+=a[j];
				else if (j>l/2+1) ans2+=a[j];
		}
		else {
			rep(j,1,l)
				if (j<=l/2) ans1+=a[j]; else ans2+=a[j];
		}
	}
	sort(s+1,s+len+1,cmp);
	rep(i,1,len) if (i&1) ans1+=s[i]; else ans2+=s[i];
	printf("%d %d",ans1,ans2);
	return 0;
}