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

const int N=1e5+5,mod=998244353;
int T,n,a[N],pre[N],ans,s[N],v[N];

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(T);
	while(T--){
		rd(n);ans=0;int sum=0;
		for(re i=1;i<=n;++i) rd(a[i]),pre[i]=0;
		for(re r=1;r<=n;++r){
			int res=a[r];pre[r]=1;
			for(re l=r-1;l>0;--l){
				int cnt=(a[l]+res-1)/res;
				if(cnt>pre[l]){
					int tmp=cnt-pre[l];pre[l]=cnt;res=a[l]/cnt;sum=(sum+1ll*tmp*l%mod)%mod;
				}
				else break;
				/*if(pre[l]==res){ans=(ans+s[l]+1ll*sum*(l)%mod)%mod;cout<<l<<' '<<r<<' '<<s[l]<<' '<<sum<<' '<<res<<endl;break;}
				if(res>=a[l]){
					res=a[l];
				//	if(pre[l]==res){ans=(ans+s[l]+1ll*sum*(l)%mod)%mod;break;}
					pre[l]=res,s[l]=(s[l]+1ll*(-v[l])*l%mod+mod)%mod,v[l]=0,ans=(ans+sum)%mod;
				}
				else{
					int cnt=(a[l]+res-1)/res;res=a[l]/cnt;
				//	if(pre[l]==res){ans=(ans+s[l]+1ll*sum*(l)%mod)%mod;break;}
					pre[l]=res;sum+=cnt-1;ans=(ans+sum)%mod;s[l]=(s[l]+1ll*(-v[l]+cnt-1)*l%mod+mod)%mod;v[l]=cnt-1;
				}*/
			}
			ans=(ans+sum)%mod;
		}
		wr(ans);puts("");
	}
	return 0;
}

// ---------- Main ---------- //