#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,E=524288,N=1000005;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	// print a signed integer
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
int n;
struct str{
	long long a[2][N];
	void clear(){
		memset(a,0,sizeof(a));
	}
	void Push(int x,int v,bool flag){
		while(x<=n){
			a[flag][x]+=v;
			x+=-x&x;
		}
	}
	long long Query(int x,bool flag)
	{
		long long ans=0;
		while(x){
			ans+=a[flag][x];
			x-=-x&x;
		}
		return ans;
	}
	long long S(long long x){
		return 1ll*x*Query(x,0)-Query(x,1);
	}
	void modify(int l,int r,int x){
		Push(l,x,0);
		Push(r+1,-x,0);
		Push(l,x*(l-1),1);
		Push(r+1,-x*r,1);
	}
	long long Query2(int l,int r){
		return S(r)-S(l-1);
	}
}t1,t2;
int b[N];
long long a[N],ans;
int sta1[N],sta2[N],top1,top2;
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	gi(n);
	int mx=0;
	for(int i=1;i<=n;++i){
		gi(a[i]);
		b[i]=__builtin_popcountll(a[i]);
		mx=max(mx,b[i]);
	}
	// cout<<mx<<endl;
	for(int i=0;i<=mx;++i){
		int s=0;
		t1.clear();
		t2.clear();
		top1=top2=0;
		for(int j=1;j<=n;++j){
			while(top1&&a[sta1[top1]]<a[j]){
				if(b[sta1[top1]]==i){
					s-=t2.Query2(sta1[top1-1]+1,sta1[top1]);
					t1.modify(sta1[top1-1]+1,sta1[top1],-1);
				}
				--top1;
			}
			sta1[++top1]=j;
			while(top2&&a[sta2[top2]]>a[j]){
				if(b[sta2[top2]]==i){
					s-=t1.Query2(sta2[top2-1]+1,sta2[top2]);
					t2.modify(sta2[top2-1]+1,sta2[top2],-1);
				}
				--top2;
			}
			sta2[++top2]=j;
			if(b[j]==i){
				s+=t2.Query2(sta1[top1-1]+1,sta1[top1]);
				t1.modify(sta1[top1-1]+1,sta1[top1],1);
				s+=t1.Query2(sta2[top2-1]+1,sta2[top2]);
				t2.modify(sta2[top2-1]+1,sta2[top2],1);
				// cout<<sta2[top2-1]+1<<' '<<sta2[top2]<<endl;
				// cout<<j<<' '<<s<<endl;
			}
			ans+=s;
		}
		// cout<<i<<endl;
	}
	cout<<ans;
}