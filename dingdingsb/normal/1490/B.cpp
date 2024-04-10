// Problem: CF1490B Balanced Remainders
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1490B
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=3e4+100;
int t,n,a[N];
int cnt[3];
signed main(){
	read(t);
	while(t--){
		read(n);
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++)
			read(a[i]),cnt[a[i]%3]++;
		int kk=n/3;int c=0,ans=0;
		cnt[0]-=kk;cnt[1]-=kk;cnt[2]-=kk;
		for(int i=0;i<3;i++)c+=(cnt[i]>0);
		if(c==0)ans=0;
		else if(c==1){
			if(cnt[0]>0)ans=-cnt[1]-2*cnt[2];
			if(cnt[1]>0)ans=-cnt[2]-2*cnt[0];
			if(cnt[2]>0)ans=-cnt[0]-2*cnt[1];
		}else{
			if(cnt[0]<0)ans=cnt[2]+2*cnt[1];
			if(cnt[1]<0)ans=cnt[0]+2*cnt[2];
			if(cnt[2]<0)ans=cnt[1]+2*cnt[0];
		}
		write(ans);pc('\n');
	}
}