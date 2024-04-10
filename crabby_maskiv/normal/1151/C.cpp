#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3f;
const ll mod=1000000007;
template<typename T>inline void read(T &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;return;
}
template<typename T,typename...Args>
	inline void read(T &x,Args &...args){
	read(x);read(args...);
}
int n,m;
ll pos[100];
ll ans;
ll q1(ll l,ll r){
	return (((r%mod)*(r%mod)-((l-1)%mod)*((l-1)%mod))%mod+mod)%mod;
}
ll q2(ll l,ll r){
	return (q1(l,r)+(r-l+1))%mod;
}
int main()
{
	int i,j;
	ll ql,qr;
	read(ql,qr);
	for(i=0;i<=61;i++)
		pos[i]=pos[i-1]+(1ll<<i);
	#ifdef TIME
		clock_t ST=clock();
	#endif
	ll t1=0,t2=0;
	for(i=0;i<=60;i++){
		if(i%2==0){
			if(pos[i]>=qr){
				ans+=q1(ql-t2,qr-t2);
				ans%=mod;
				cout<<ans;
				return 0;
			}
			if(pos[i]>=ql){
				ans+=q1(ql-t2,pos[i]-t2);
				ql=pos[i]+1;
				ans%=mod;
			}
			t1+=(1ll<<i);
		}
		else{
			if(pos[i]>=qr){
				ans+=q2(ql-t1,qr-t1);
				ans%=mod;
				cout<<ans;
				return 0;
			}
			if(pos[i]>=ql){
				ans+=q2(ql-t1,pos[i]-t1);
				ql=pos[i]+1;
				ans%=mod;
			}
			t2+=(1ll<<i);
		}
	}
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	
	return 0;
}