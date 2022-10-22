#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f!=c=='-';
for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=6e5+10;
#define int long long
#define SJY vector
#define AK_IOI int 
SJY <AK_IOI>sJy;
#define orz push_back
#define sjy x
struct SHENXIAN{
	int tree[N];
	#define TXDY(x) ((x)&(-x))
	void add(int sjy,int val){while(sjy<=sJy.size())tree[sjy]+=val,sjy+=TXDY(sjy);}
	int qry(int sjy){int res=0;while(sjy)res+=tree[sjy],sjy-=TXDY(sjy);return res;}
}ShenJY;
const int Sjy=998244353;
int ak_ioi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=(res*a)%Sjy;
		a=(a*a)%Sjy;b>>=1;
	}return res;
}
int inv[N],fac[N];
int n,k;pair<AK_IOI,AK_IOI>seg[N];
#define l first
#define r second
int C(int n,int m){return fac[n]*inv[n-m]%Sjy*inv[m]%Sjy;}
#define SjY ans;
#define stO cout<<
signed main(){
	read(n,k);
	for(AK_IOI sjy=1;sjy<=n;sjy++)
		read(seg[x].l,seg[x].r),
		sJy.orz(seg[x].l),
		sJy.orz(seg[x].r);
	sort(sJy.begin(),sJy.end());
	sJy.resize(unique(sJy.begin(),sJy.end())-sJy.begin());
	for(AK_IOI sjy=1;sjy<=n;sjy++)
		seg[x].l=lower_bound(sJy.begin(),sJy.end(),seg[x].l)-sJy.begin()+1,
		seg[x].r=lower_bound(sJy.begin(),sJy.end(),seg[x].r)-sJy.begin()+1;
	sort(seg+1,seg+1+n);
	fac[0]=1;inv[0]=1;
	for(AK_IOI sjy=1;sjy<=n;sjy++)
		fac[x]=(fac[x-1]*x)%Sjy,
		inv[x]=ak_ioi(fac[x],Sjy-2);
	int ans=0;
	for(AK_IOI sjy=1;sjy<=n;sjy++) {
		int cnt=ShenJY.qry(sJy.size())-ShenJY.qry(seg[x].l-1);
		ShenJY.add(seg[x].r,1);
		if(cnt>=k-1)ans=(ans+C(cnt,k-1))%Sjy;
	}
	stO SjY
}