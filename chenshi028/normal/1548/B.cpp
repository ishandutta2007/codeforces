#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline long long Abs(long long x){return x<0?-x:x;}
inline int Max(int a,int b){return a>b?a:b;}
const int o=2e5+10;
int T,n,lg[o],ans;long long st[o][20];
long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
long long query(int l,int r){int t=lg[r-l+1];return gcd(st[l][t],st[r-(1<<t)+1][t]);}
int main(){
	for(read(T);T--;printf("%d\n",ans+1)){
		read(n);lg[ans=0]=-1;for(int i=1;i<=n;++i) lg[i]=lg[i>>1]+1;
		for(int i=0;i<n;++i) read(st[i][0]);
		for(int i=n-1;i;--i) st[i][0]=Abs(st[i][0]-st[i-1][0]);
		for(int i=1;i<20;++i) for(int j=1;j<=n;++j)
			if(j+(1<<(i-1))<=n) st[j][i]=gcd(st[j][i-1],st[j+(1<<(i-1))][i-1]);else st[j][i]=st[j][i-1];
		for(int i=1,l,r,md;i<n;ans=Max(ans,l-i+1),++i) for(l=i-1,r=n-1;l<r;) if(query(i,md=(l+r>>1)+1)>1) l=md;else r=md-1;
	}
	return 0;
}