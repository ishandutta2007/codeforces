// Problem: CF685C Optimal Point
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF685C
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=1e5+10;
typedef long long ll;
int t,n;
ll x[N],y[N],z[N];
const ll inf=4e18;
#define chkmx(a,b) ((a)<(b)?(a)=(b):(a))
#define chkmn(a,b) ((a)>(b)?(a)=(b):(a))
signed main(){
	read(t);
	while(t--){
		ll L1=-inf,R1=inf;
		ll L2=-inf,R2=inf;
		ll L3=-inf,R3=inf;
		ll L4=-inf,R4=inf;
		read(n);
		for(int i=1;i<=n;i++){
			read(x[i],y[i],z[i]);
			chkmx(L1,x[i]+y[i]+z[i]);
			chkmn(R1,x[i]+y[i]+z[i]);
			chkmx(L2,x[i]+y[i]-z[i]);
			chkmn(R2,x[i]+y[i]-z[i]);
			chkmx(L3,x[i]-y[i]+z[i]);
			chkmn(R3,x[i]-y[i]+z[i]);
			chkmx(L4,-x[i]+y[i]+z[i]);
			chkmn(R4,-x[i]+y[i]+z[i]);
		}
		ll l=0,r=4e18,ans=0;
		auto fun=[&](ll d,bool out=false){
			ll l1=L1-d,r1=R1+d;
			ll l2=L2-d,r2=R2+d;
			ll l3=L3-d,r3=R3+d;
			ll l4=L4-d,r4=R4+d;
			for(int i=0;i<2;i++){
				ll l11=l1+((l1&1)^i);
				ll r11=r1-((r1&1)^i);
				ll l21=l2+((l2&1)^i);
				ll r21=r2-((r2&1)^i);
				ll l31=l3+((l3&1)^i);
				ll r31=r3-((r3&1)^i);
				ll l41=l4+((l4&1)^i);
				ll r41=r4-((r4&1)^i);
				if(l11<=r11&&l21<=r21&&l31<=r31&&l41<=r41){
					long long a=l21;
					long long b=l31;
					long long c=l41;
					if(a+b+c<=r11){
						if(a+b+c<l11){
							if(r21<l11-b-c)
								a=r21;
							else
								a=l11-b-c;
						}
						if(a+b+c<l11){
							if(r31<l11-a-c)
								b=r31;
							else
								b=l11-a-c;
						}
						if(a+b+c<l11){
							if(r41<l11-a-b)
								c=r41;
							else
								c=l11-a-b;
						}
						if(a+b+c>=l11){
							if(out)
								write((b+a)/2),putchar(' '),
								write((a+c)/2),putchar(' '),
								write((c+b)/2),putchar('\n');
							return 1;
						}
					}
				}
			}
			return 0;
		};
		fun(0);
		while(l<=r){
			ll mid=l+r>>1;
			if(fun(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
		fun(ans,true);
	}
}