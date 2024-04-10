// Problem: CF730I Olympiad in Programming and Sports
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF730I
// Memory Limit: 500 MB
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
const int N=3e3+100;
const int inf=0x3f3f3f3f;
int n,p,s,a[N],b[N],id[N],arr[N],ans;
signed main(){
	read(n,p,s);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(b[i]);
	for(int i=1;i<=n;i++)arr[i]=i;
	sort(arr+1,arr+1+n,[&](int i,int j)->bool{return a[i]>a[j];});
	for(int i=1;i<=p;i++)ans+=a[arr[i]],id[arr[i]]=1;
	for(int i=1;i<=s;i++){
		//id=1ai-bi
		//id=0ai
		//id=0bi
		pair<int,int>mx0=mp(-inf,0),mx1=mp(-inf,0),mx2=mp(-inf,0);
		for(int j=1;j<=n;j++)
			if(id[j]==0)chkmx(mx1,mp(a[j],j)),chkmx(mx2,mp(b[j],j));
			else if(id[j]==1)chkmx(mx0,mp(b[j]-a[j],j));
		if(mx0.fi+mx1.fi>mx2.fi){
			ans+=mx0.fi+mx1.fi;
			id[mx0.se]=2;
			id[mx1.se]=1;
		}else{
			ans+=mx2.fi;
			id[mx2.se]=2;
		}
	}
	write(ans);pc('\n');
	for(int i=1;i<=n;i++)if(id[i]==1)write(i),pc(' ');pc('\n');
	for(int i=1;i<=n;i++)if(id[i]==2)write(i),pc(' ');
}