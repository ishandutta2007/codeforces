// Problem: F2. Gregor and the Odd Cows (Hard)
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/F2
// Memory Limit: 256 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
//#define int long long
typedef long long ll;
const int N=6100;
int n,x[N],y[N],cnt[4][4][4];
int S2(int x1,int y1,int x2,int y2,int x3,int y3){
	int res=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
	res%=4;if(res<0)res+=4;return res;
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)
		read(x[i],y[i]);
	ll eee=0,eoo=0;
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof cnt);
		for(int j=1;j<=n;j++)if(i!=j)
			cnt[x[j]%4][y[j]%4][__gcd(abs(x[i]-x[j]),abs(y[i]-y[j]))%4]++;
		for(int x1=0;x1<4;x1++)for(int y1=0;y1<4;y1++)for(int b1=0;b1<4;b1++){
			int kk=cnt[x1][y1][b1];cnt[x1][y1][b1]--;
			for(int x2=x1&1;x2<4;x2+=2)for(int y2=y1&1;y2<4;y2+=2)for(int b2=b1&1;b2<4;b2+=2){
				int S=S2(x[i],y[i],x1,y1,x2,y2);
				if(S&1)exit(-1);
				S>>=1;
				int b3=__gcd(abs(x1-x2),abs(y1-y2));
				int res=S-(b1+b2+b3)/2+1;
				if(res&1){
					if(b1&1)eoo+=kk*cnt[x2][y2][b2];
					else eee+=kk*cnt[x2][y2][b2];
				}
			}
			cnt[x1][y1][b1]++;
		}
	}
	write(eee/6+eoo/2);
}