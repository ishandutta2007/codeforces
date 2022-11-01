#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long
const int N = 1000005, P = 998244353;
int n, lenl, lenr, extl[N], extr[N], f[N], sum[N];
char s[N], l[N<<1], r[N<<1];
inline void exkmp(char *s, int n, char *t, int m, int *ext){
	t[++m]='#', memcpy(t+m+1, s+1, n), m+=n;
	static int nxt[N<<1];
	for(int i=2, p=1, *nx=nxt+i; i<=m; ++i, ++nx){
		*nx=max(0, min(nxt[i-p+1], p+nxt[p]-i));
		while(t[*nx+1]==t[i+*nx]) ++*nx;
		if(i+*nx>p+nxt[p]) p=i;
	}
	memcpy(ext+1, nxt+m-n+1, n<<2);
}
int main() {
	scanf("%s%s%s", s+1, l+1, r+1);
	n=strlen(s+1), lenl=strlen(l+1), lenr=strlen(r+1);
	exkmp(s, n, l, lenl, extl), exkmp(s, n, r, lenr, extr);
	sum[0]=f[0]=1;
	for(int i=1; i<=n; ++i){
		if(i>=lenl){
			int L, R=i-lenl;
			if(extl[R+1]<lenl && s[R+extl[R+1]+1]<l[extl[R+1]+1]) --R;
			if(i>=lenr){
				L=i-lenr;
				if(extr[L+1]<lenr && s[L+extr[L+1]+1]>r[extr[L+1]+1]) ++L;
			}
			else L=0;
			f[i]=(L?(sum[R]-sum[L-1])%P:sum[R]);
		}
		if(s[i]=='0' && l[1]=='0') (f[i]+=f[i-1])%=P;
		if(s[i+1]!='0') sum[i]=(sum[i-1]+f[i])%P; else sum[i]=sum[i-1];
	}
	return printf("%d", (f[n]+P)%P), 0;
}