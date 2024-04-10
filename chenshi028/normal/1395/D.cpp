#include<cstdio>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a){
	char c=getchar();int f=1;a=0;
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') a=(a<<1)+(a<<3)+c-48,c=getchar();
	a*=f;
}
template<class T>void write(T a){
	if(a<0) putchar('-'),a=-a;
	if(a>9) write(a/10);
	putchar(a%10+48);
}
const int o=1e5+10;
#define int long long
inline int max(int a,int b){return a>b?a:b;}
int n,d,m,a[o],x[o],y[o],cnt1,cnt2,s1[o],s2[o],ans;
signed main(){
	read(n);read(d);read(m);
	for(int i=1;i<=n;++i){read(a[i]);if(a[i]>m) x[++cnt1]=a[i];else y[++cnt2]=a[i];}
	if(cnt1) sort(x+1,x+cnt1+1);
	if(cnt2) sort(y+1,y+cnt2+1);
	for(int i=1;i<=cnt1;++i) s1[i]=s1[i-1]+x[cnt1-i+1];for(int i=n;i^cnt1;--i) s1[i]=s1[cnt1];
	for(int i=1;i<=cnt2;++i) s2[i]=s2[i-1]+y[cnt2-i+1];for(int i=n;i^cnt2;--i) s2[i]=s2[cnt2];
	ans=s2[n];
	for(int i=1;i<=cnt1&&(i-1)*(d+1)<n;++i) ans=max(ans,s1[i]+s2[n-(i-1)*(d+1)-1]);
	write(ans);
	return 0;
}