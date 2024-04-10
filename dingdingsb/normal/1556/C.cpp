#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=1e3+100;
int n,a[N],ans;
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(i[a]);
	for(int i=1;i<=n;i+=2){
		int mn=1,delta=0;//delta=-
		for(int j=i+1;j<=n;j++)
			if(!(j&1)){
				ans+=max(0ll,min(a[i]-mn+1,a[j]-mn-delta+1));
				delta-=a[j];chkmx(mn,-delta);
			}else delta+=a[j];
	}
	write(ans);
}