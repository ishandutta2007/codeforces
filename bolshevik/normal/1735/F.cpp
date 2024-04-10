#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
const int o=3e5+10;
int T,n;long long p[o],q[o];long double a,b,X1,Y1,X2,Y2;
struct Segment{
	long long lx,ly;long double x,y;
	Segment(long long lx_=0,long long ly_=0):lx(lx_),ly(ly_){x=lx;y=ly;}
	inline bool operator<(const Segment&b)const
	{if(ly*b.lx-b.ly*lx) return ly*b.lx<b.ly*lx;if(lx^b.lx) return lx<b.lx;return x<b.x;}
}s;
multiset<Segment> S;
int main(){
	for(scanf("%d",&T);T--;S.clear()){
		scanf("%d%Lf%Lf",&n,&a,&b);Y1=b;X2=a;X1=Y2=0;
		for(int i=1;i<=n;++i) scanf("%lld",&p[i]);
		for(int i=1;i<=n;++i) scanf("%lld",&q[i]);
		if(a) S.insert(Segment(a,0));
		if(b) S.insert(Segment(0,b));
		for(int i=1;i<=n;++i,printf("%.9Lf\n",X2)){
			S.insert(Segment(2*p[i],2*q[i]));
			X1-=p[i];Y1+=q[i];X2+=p[i];Y2-=q[i];
			for(;X1<0;){
				if(S.empty()){X1=0;break;}
				s=*S.begin();S.erase(S.find(s));
				if(X1+s.x<=0) X1+=s.x,Y1-=s.y;
				else Y1+=s.y/s.x*X1,s.y*=(s.x+X1)/s.x,s.x+=X1,X1=0,S.insert(s);
			}
			for(;Y2<0;){
				if(S.empty()){Y2=0;break;}
				s=*--S.end();S.erase(S.find(s));
				if(Y2+s.y<=0) Y2+=s.y,X2-=s.x;
				else X2+=s.x/s.y*Y2,s.x*=(s.y+Y2)/s.y,s.y+=Y2,Y2=0,S.insert(s);
			}
		}
	}
	return 0;
}