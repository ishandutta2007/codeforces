// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back

using namespace std;
typedef long long ll;

template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}

// ---------- IO ---------- //

const int N=4e5+5;
int n,m,k[N],len,sum[N],nxt[N],tot,op,qaq,qwq;

inline int block(int x){return (x-1)/len+1;}
inline int L(int x){return (x-1)*len+1;}
inline int R(int x){return x*len;}

inline void init(){
	for(re nw=1;nw<=tot;nw++){
		int l=L(nw),r=R(nw);
		for(re i=r;i>=l;i--){
			if(i+k[i]>n) sum[i]=1,nxt[i]=i+k[i];
			else if(i+k[i]>r) sum[i]=1,nxt[i]=i+k[i];
			else sum[i]=sum[i+k[i]]+1,nxt[i]=nxt[i+k[i]];
		}
	}
}

inline void query(int x){
	int ans=0;
	while(nxt[x]<=n) ans+=sum[x],x=nxt[x];
	while(x+k[x]<=n) x+=k[x],ans++;
	wr(x);putchar(' ');wr(ans+1);puts("");
}

inline void modify(int x,int y){
	int nw=block(x),l=L(nw),r=R(nw);
	k[x]=y;
	for(re i=x;i>=l;i--){
		if(i+k[i]>n) sum[i]=1,nxt[i]=i+k[i];
		if(i+k[i]>r) sum[i]=1,nxt[i]=i+k[i];
		else sum[i]=sum[i+k[i]]+1,nxt[i]=nxt[i+k[i]];
	}
}

// ---------- Sqrt & Operations ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);rd(m);len=(int)sqrt(n);tot=block(n);
	for(re i=1;i<=n;i++) rd(k[i]);
	init();
	for(re i=0;i<m;i++){
		rd(op);rd(qaq);
		if(op==1) query(qaq);
		else rd(qwq),modify(qaq,qwq);
	}
	return 0;
}

// ---------- Main ---------- //