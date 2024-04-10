// Problem: CF1601D Difficult Mountain
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1601D
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
#define a first
#define s second
const int N=5e5+100;
int n,d,tot1,tot2;pair<int,int>p1[N],p2[N];
signed main(){
	read(n,d);int ans=0;
	for(int i=1;i<=n;i++){
		int a,s;read(s,a);
		if(s<d)continue;
		if(a<=d)ans++;
		else if(a<=s)p1[++tot1]=mp(a,s);
		else p2[++tot2]=mp(a,s);
	}
	sort(p1+1,p1+tot1+1,[&](pair<int,int>x,pair<int,int>y)->bool{return x.s<y.s;});
	sort(p2+1,p2+tot2+1,[&](pair<int,int>x,pair<int,int>y)->bool{return x.a<y.a;});
	int i=1,j=1;
	for(;i<=tot1;i++){
		while(j<=tot2&&p2[j].a<=p1[i].s){
			if(p2[j].s>=d)ans++,d=p2[j].a;
			j++;
		}
		if(p1[i].s>=d)
		chkmx(d,p1[i].a);
		ans++;
	}
	while(j<=tot2){
		if(p2[j].s>=d)ans++,chkmx(d,p2[j].a);
		j++;
	}
	write(ans);
}