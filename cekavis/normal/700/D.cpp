#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>
#include<queue>

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

const int N = 100005;
int n, q, cnt, e[1<<9|1], ans[N], a[N], c[N], d[N], que[N<<1];
bool vis[N];
struct query{
	int l, r, id;
	inline bool operator <(const query &rhs)const{
		return l>>8==rhs.l>>8?(l>>8&1?r>rhs.r:r<rhs.r):l<rhs.l;
	}
} b[N];
inline void ins(int x){
	// printf("ins: %d\n", x);
	--d[c[x]], ++d[++c[x]];
	que[++cnt]=c[x];
}
inline void del(int x){
	// printf("del: %d\n", x);
	--d[c[x]], ++d[--c[x]];
	if(c[x]) que[++cnt]=c[x];
}
int main() {
	read(n);
	for(int i=1; i<=n; ++i) read(a[i]);
	read(q);
	for(int i=1; i<=q; ++i) read(b[i].l), read(b[i].r), b[i].id=i;
	sort(b+1, b+q+1);
	int l=1, r=0;
	for(int i=1; i<=q; ++i){
		while(l>b[i].l) ins(a[--l]);
		while(r<b[i].r) ins(a[++r]);
		while(l<b[i].l) del(a[l++]);
		while(r>b[i].r) del(a[r--]);
		// printf(">> %d\n", b[i].id);
		int now=0, Ans=0;
		for(int j=1; j<=cnt; ++j) if(d[que[j]] && !vis[que[j]]) vis[que[j]]=1, que[++now]=que[j];
		cnt=now;
		priority_queue<int, vector<int>, greater<int>> h;
		for(int j=1; j<=cnt; ++j){
			// printf("que: %d %d\n", que[j], d[que[j]]);
			vis[que[j]]=0;
			if(que[j]>1<<9) for(int k=0; k<d[que[j]]; ++k) h.push(que[j]);
		}
		memcpy(e+1, d+1, 4<<9);
		for(int i=1; i<=1<<9; ++i){
			if(e[i]>1){
				if(i<<1<=1<<9) e[i<<1]+=e[i]>>1, Ans+=(e[i]>>1)*i<<1, e[i]&=1;
				else while(e[i]>1) e[i]-=2, Ans+=i<<1, h.push(i<<1);
			}
			// printf("Ans = %d\n", Ans);
			if(e[i]){
				int j=i+1;
				while(j<=1<<9 && !e[j]) ++j;
				if(j<=1<<9){
					if(i+j<=1<<9) ++e[i+j]; else h.push(i+j);
					--e[i], --e[j], Ans+=i+j;
				}
				else h.push(i);
				i=j-1;
			}
		}
		while(h.size()>1){
			int x=h.top();
			h.pop();
			int y=h.top();
			h.pop();
			Ans+=x+y, h.push(x+y);
		}
		ans[b[i].id]=Ans;
	}
	for(int i=1; i<=q; ++i) print(ans[i]), print('\n');
	return flush(), 0;
}