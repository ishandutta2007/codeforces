// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[40]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=1005;
int n,m1,m2,fa1[N],fa2[N],ans,qaq[N*N][2];

inline int find1(int x){return fa1[x]==x?x:fa1[x]=find1(fa1[x]);}
inline void merge1(int x,int y){fa1[find1(x)]=find1(y);}

inline int find2(int x){return fa2[x]==x?x:fa2[x]=find2(fa2[x]);}
inline void merge2(int x,int y){fa2[find2(x)]=find2(y);}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(n);rd(m1);rd(m2);
	for(re i=1;i<=n;++i) fa1[i]=fa2[i]=i;
	for(re i=1;i<=m1;++i){
		int x,y;rd(x);rd(y);merge1(x,y);
	}
	for(re i=1;i<=m2;++i){
		int x,y;rd(x);rd(y);merge2(x,y);
	}
	for(re i=1;i<=n;++i)
		for(re j=i+1;j<=n;++j)
			if(find1(i)!=find1(j)&&find2(i)!=find2(j)) qaq[++ans][0]=i,qaq[ans][1]=j,merge1(i,j),merge2(i,j);
	wr(ans);puts("");
	for(re i=1;i<=ans;++i) wr(qaq[i][0]),putchar(' '),wr(qaq[i][1]),puts("");
	return 0;
}

// ---------- Main ---------- //