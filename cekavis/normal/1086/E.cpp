#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig=false, c=read(); !isdigit(c); c=read()) {
		if (c == '-') iosig=true;
		if (c == -1) return;
	}
	for (x=0; isdigit(c); c=read()) x=((x+(x<<2))<<1)+(c^'0');
	if (iosig) x=-x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh=obuf;
inline void print(char c) {
	if (ooh==obuf+OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh=obuf;
	*ooh++=c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x==0) print('0');
	else {
		if (x<0) print('-'), x=-x;
		for (cnt=0; x; x/=10) buf[++cnt]=x%10+48;
		while(cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }

const int N = 2005, P = 998244353;
int n, ans, s1[N], s2[N], f[N], ff[N], fac[N], a[N][N], g[N][N];
bool vis[N], ch[N];
int query(int *s, int x){
	int ans=0;
	while(x) ans+=s[x], x-=x&-x;
	return ans;
}
void modify(int *s, int x, int y){
	while(x<=n) s[x]+=y, x+=x&-x;
}
void change(int x){
	ch[x]=1, modify(s2, x, -1), modify(s1, x, 1);
}
int main() {
	read(n);
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) read(a[i][j]);
	f[0]=1, f[1]=0;
	for(int i=2; i<=n; ++i) f[i]=(ll)(f[i-1]+f[i-2])*(i-1)%P;
	ff[0]=1;
	for(int i=1; i<=n; ++i) ff[i]=(ll)ff[i-1]*f[n]%P;
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=(ll)fac[i-1]*i%P;
	for(int i=0; i<=n; ++i) g[0][i]=f[i];
	for(int i=1; i<=n; ++i)
		for(int j=0; i+j<=n; ++j)
			g[i][j]=(g[i-1][j]+g[i-1][j+1])%P;

	for(int i=1; i<=n; ++i){
		int cnt=0;
		for(int j=i+1; j<=n; ++j) if(a[1][j]<a[1][i]) ++cnt;
		ans=(ans+(ll)fac[n-i]*cnt)%P;
	}
	ans=(ll)ans*ff[n-1]%P;
	for(int i=2; i<=n; ++i){
		memset(s1, 0, sizeof s1), memset(vis, 0, sizeof vis), memset(ch, 0, sizeof ch);
		for(int j=1; j<=n; ++j) s2[j]=j&-j;

		int cnt1=0, cnt2=n, tot=0;
		for(int j=1; j<=n; ++j){
			int t=query(s1, a[i][j]-1), k=query(s2, a[i][j]-1);
			if(a[i-1][j]<a[i][j] && !vis[a[i-1][j]]) --(ch[a[i-1][j]]?t:k);
			modify(ch[a[i][j]]?s1:s2, a[i][j], -1);
			vis[a[i][j]]=1;
			if(ch[a[i-1][j]]){
				tot=(tot+(ll)g[cnt1-1][cnt2]*t+(ll)g[cnt1][cnt2-1]*k)%P;
				--(ch[a[i][j]]?cnt1:cnt2);
				// printf("[%d]", ch[a[i][j]]);
			}
			else{
				vis[a[i-1][j]]=1;
				tot=(tot+(ll)g[cnt1][cnt2-1]*t+(ll)g[cnt1+1][cnt2-2]*k)%P;
				ch[a[i][j]]?--cnt2:(cnt2-=2, ++cnt1);
				change(a[i-1][j]);
			}
			ch[a[i][j]]=1;
			// printf(">> %d %d\n", cnt1, g[1][0]);
		}
		// puts("-------");
		ans=(ans+(ll)tot*ff[n-i])%P;
	}
	return printf("%d", ans), 0;
}