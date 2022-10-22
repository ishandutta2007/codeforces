#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=6010;
inline int Abs(int x){if(x<0) x=-x;return x;} 
inline int mod(int x){x%=4;if(x<0) x+=4;return x;}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int n,cnt[o][4][4][4],x[o],y[o];long long ans[2];
int main(){
	read(n);
	for(int i=1;i<=n;++i) read(x[i]),read(y[i]);
	for(int i=1,t;i<=n;++i) for(int j=n;j>i;--j)
		++cnt[i][mod(x[j]-x[i])][mod(y[j]-y[i])][t=mod(gcd(Abs(y[j]-y[i]),Abs(x[j]-x[i])))],++cnt[j][mod(x[i]-x[j])][mod(y[i]-y[j])][t];
	for(int i=1,a,b;i<=n;++i) for(int xx1=0;xx1<4;++xx1) for(int yy1=0;yy1<4;++yy1)
		for(int xx2=0;xx2<4;++xx2) if((xx1-xx2)%2==0) for(int yy2=0;yy2<4;++yy2) if((yy1-yy2)%2==0)
			if((a=mod(xx1*yy2-xx2*yy1))%2==0) for(int b1=0;b1<4;++b1)
				if(xx1==xx2&&yy1==yy2)
					if(b1==mod(a-b1)) ans[b1&1]+=cnt[i][xx1][yy1][b1]*1ll*(cnt[i][xx2][yy2][b1]-1);
					else ans[b1&1]+=cnt[i][xx1][yy1][b1]*1ll*cnt[i][xx2][yy2][mod(a-b1)];
				else ans[b1&1]+=cnt[i][xx1][yy1][b1]*1ll*cnt[i][xx2][yy2][mod(a-b1-2)];
	printf("%lld",ans[1]/2+ans[0]/6);
	return 0;
}