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
	int tmp[30]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=21;
int n,cnt[(1<<11)+5],all;
ll a[(1<<N)+5],b[(1<<N)+5],c[(1<<N)+5];
char s1[(1<<N)+5],s2[(1<<N)+5];

inline int count(int x){return cnt[x&2047]+cnt[x>>11];}

inline void OR(ll *f,int n,int op){
	for(re s=2,k=1;s<=n;s<<=1,k<<=1)
		for(re i=0;i<n;i+=s)
			for(re j=0;j<k;++j)
				if(op==1) f[i+j+k]=f[i+j+k]+f[i+j];
				else f[i+j+k]=f[i+j+k]-f[i+j];
}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	for(re i=1;i<2048;++i) cnt[i]=cnt[i>>1]+(i&1);
	rd(n);all=(1<<n); scanf("%s%s",s1,s2);
	for(re i=0;i<all;++i) a[i]=(s1[i]&15ll)<<(count(i)<<1),b[i]=(s2[i]&15ll)<<(count(i)<<1);
	OR(a,all,1);OR(b,all,1);
	for(re i=0;i<all;++i) c[i]=a[i]*b[i];
	OR(c,all,-1);
	for(re i=0;i<all;++i) wr((c[i]>>(count(i)<<1))&3ull);puts("");
	return 0;
}

// ---------- Main ---------- //