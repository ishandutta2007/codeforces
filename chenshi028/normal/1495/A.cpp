#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
const int o=1e5+10;
inline int Abs(int x){return x<0?-x:x;}
int T,n,rd,cx,cy;double ans,x[o],y[o];
int main(){
	read(T);while(T--){
		read(n);ans=cx=cy=0;for(int i=1;i<=2*n;++i){read(rd);if(rd) x[++cx]=Abs(rd),read(rd);else read(rd),y[++cy]=Abs(rd);}
		sort(x+1,x+1+n);sort(y+1,y+1+n);
		for(int i=1;i<=n;++i) ans+=sqrt(x[i]*x[i]+y[i]*y[i]);
		printf("%.15lf\n",ans);
	}
	return 0;
}