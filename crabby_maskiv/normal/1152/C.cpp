#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=300005;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
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
ll n,m;
ll gcd(ll a,ll b){
	if(!b) return a;
	else return gcd(b,a%b);
}
ll query(ll x){
	return (m+x-1)/x*x-m;
}
int main(){
	ios::sync_with_stdio(0);
	ll i,j;
	read(n,m);
	if(n>m) swap(n,m);
	#ifdef TIME
		clock_t ST=clock();
	#endif
	ll ans=n*m/gcd(n,m),pos=0;
	for(i=1;i*i<=m-n;i++){
		if((m-n)%i==0){
			ll q1=query(i),q2=query((m-n)/i);
			if((n+q1)*(m+q1)/(gcd(n+q1,m+q1))<ans){
				ans=(n+q1)*(m+q1)/(gcd(n+q1,m+q1));
				pos=q1;
			}
			else if((n+q2)*(m+q2)/(gcd(n+q2,m+q2))<ans){
				ans=(n+q2)*(m+q2)/(gcd(n+q2,m+q2));
				pos=q2;
			}
		}
	}
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	cout<<pos;
	return 0;
}