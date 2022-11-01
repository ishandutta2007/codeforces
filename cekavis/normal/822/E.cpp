#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
#define ll long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
const int N = 100005, K = 32, P = 1000000007;
int x, n, m, f[N][K], p[N], ss[N], tt[N];
char s[N], t[N];
inline void chkmx(int &x, int y){ x=(x>y?x:y);}
inline int lcp(int x, int y){
	int l=0, r=min(n-x+1, m-y+1), ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if((ss[x+mid-1]+(ll)tt[y-1]*p[mid])%P==(tt[y+mid-1]+(ll)ss[x-1]*p[mid])%P) ans=mid, l=mid+1; else r=mid-1;
	}
	return ans;
}
int main() {
	scanf("%d%s%d%s%d", &n, s+1, &m, t+1, &x);
	p[0]=1;
	rep(i, 1, n) ss[i]=((ll)ss[i-1]*27+s[i]-'a')%P, p[i]=(ll)p[i-1]*27%P;
	rep(i, 1, m) tt[i]=((ll)tt[i-1]*27+t[i]-'a')%P;
	rep(i, 0, n) rep(j, 1, x){
		chkmx(f[i+1][j], f[i][j]);
		int tmp=lcp(i+1, f[i][j]+1);
		if(f[i][j]+tmp==m) return puts("YES"), 0;
		chkmx(f[i+tmp][j+1], f[i][j]+tmp);
	}
	return puts("NO"), 0;
}