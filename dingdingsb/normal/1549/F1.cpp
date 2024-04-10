// Problem: F1. Gregor and the Odd Cows (Easy)
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/F1
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
int n,x[N],y[N];
int cnt[4][4];//x,ymod4?
vector<pair<int,int>>can[4][4][4][4];
bool chk(int x1,int y1,int x2,int y2,int x3,int y3){
	int S=x1*y2-x1*y3+x2*y3-x2*y1+x3*y1-x2*y2;
	int b=__gcd(abs(x1-x2),abs(y1-y2))+__gcd(abs(x1-x3),abs(y1-y3))+__gcd(abs(x2-x3),abs(y2-y3));
	if(b%2)
		printf("");
	int ans=S-b/2+1;ans%=2;if(ans<0)ans+=2;
	return ans;
}
signed main(){
	for(int a=0;a<4;a+=2)for(int b=0;b<4;b+=2)
		for(int c=0;c<4;c+=2)for(int d=0;d<4;d+=2)
			for(int e=0;e<4;e+=2)for(int f=0;f<4;f+=2)
				if(chk(a,b,c,d,e,f))can[a][b][c][d].pb({e,f});
	read(n);
	for(int i=1;i<=n;i++)
		read(x[i],y[i]),x[i]%=4,y[i]%=4;
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)cnt[x[j]][y[j]]++;
		for(int j=i+1;j<=n;j++){
			cnt[x[j]][y[j]]--;
			for(auto [a,b]:can[x[i]][y[i]][x[j]][y[j]])
				ans+=cnt[a][b];
		}
	}
	write(ans);
}