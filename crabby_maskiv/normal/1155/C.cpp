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
int n,m;
ll a[N],b[N];
ll gcd(ll a,ll b){
	if(!b) return a;
	else return gcd(b,a%b);
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	read(n,m);
	for(i=1;i<=n;i++) read(a[i]);
	for(i=1;i<=m;i++) read(b[i]);
	#ifdef TIME
		clock_t ST=clock();
	#endif
	ll k=0;
	sort(a+1,a+n+1);
	for(i=1;i<n;i++){
		k=gcd(k,a[i+1]-a[i]);
	}
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	for(i=1;i<=m;i++){
		if(k%b[i]==0){
			cout<<"YES"<<endl;
			cout<<a[1]<<" "<<i;
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}