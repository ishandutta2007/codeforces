// luogu-judger-enable-o2
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
const double eps=1e-7;
const double pi=acos(-1);
const int maxn=305;
struct Vec {
	double x,y;
	Vec() {}
	Vec(double _x,double _y) {
		x=_x;
		y=_y;
	}
	friend Vec operator + (Vec a,Vec b) {
		return Vec(a.x+b.x,a.y+b.y);
	}
	friend Vec operator - (Vec a,Vec b) {
		return Vec(a.x-b.x,a.y-b.y);
	}
	friend double operator * (Vec a,Vec b) {
		return a.x*b.y-a.y*b.x;
	}
	friend double operator ^ (Vec a,Vec b) {
		return a.x*b.x-a.y*b.y;
	}
};
inline double cross(Vec a,Vec b,Vec c) {
	return (b-a)*(c-a);   //
}
inline bool segts(Vec a,Vec b,Vec c,Vec d) { //
	double h1=cross(a,b,c)*cross(a,b,d),h2=cross(c,d,a)*cross(c,d,b);
	if (h1<0.0&&h2<0.0) return 1;
	else return 0;
}
inline bool lints(Vec a,Vec b,Vec c,Vec d) { //
	double h1=cross(a,b,c)*cross(a,b,d);
	if (h1<=0.0) return 1;
	else return 0;
}
inline bool lintl(Vec a,Vec b,Vec c,Vec d) { //
	if ((b-a)*(d-c)==0.0) return 1;
	if (cross(a,b,d)==0.0) return 0;
	else return 1;
}
inline Vec llcro(Vec a,Vec b,Vec c,Vec d) { //
	double s1=(d-a)*(c-a),s2=(c-b)*(d-b)+s1;
	b.x=a.x+(b.x-a.x)/s2*s1;
	b.y=a.y+(b.y-a.y)/s2*s1;
	return b;
}
inline double ppdis(Vec x,Vec y) { //
	double kk=(y.y-x.y)*(y.y-x.y)+(y.x-x.x)*(y.x-x.x);
	return sqrt(kk);
}
inline double pldis(Vec a,Vec b,Vec c) { //
	return fabs(cross(b,a,c)/ppdis(b,c));
}
inline double angle(Vec a,Vec b,Vec c,Vec d) { //
	Vec c1=llcro(a,b,c,d);
	return asin(cross(c1,a,c)/ppdis(c1,a)/ppdis(c1,c))/pi*180.0;
}
double nu,nd,nl,nr,mu,md,ml,mr,mx,my;
struct line {
	Vec a,b;
} k1[10],k2[10];
int main() {
	nu=nr=mu=mr=-105;
    nd=nl=md=ml=105;
	Vec a1,a2,a3,a4;
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a1.x,&a1.y,&a2.x,&a2.y,&a3.x,&a3.y,&a4.x,&a4.y);
	k1[1]=line {a1,a2};
	k1[2]=line {a2,a3};
	k1[3]=line {a3,a4};
	k1[4]=line {a4,a1};
	for (int i=1;i<=4;++i){
		double x=k1[i].a.x,y=k1[i].a.y;
		nd=min(nd,y);
        nu=max(nu,y);
        nl=min(nl,x);
		nr=max(nr,x);
	}
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a1.x,&a1.y,&a2.x,&a2.y,&a3.x,&a3.y,&a4.x,&a4.y);
	k2[1]=line {a1,a2};
	k2[2]=line {a2,a3};
	k2[3]=line {a3,a4};
	k2[4]=line {a4,a1};
	
	for (int i=1;i<=4;++i){
		double x=k2[i].a.x,y=k2[i].a.y;
		md=min(md,y);
        mu=max(mu,y);
        ml=min(ml,x);
        mr=max(mr,x);
	}
	mx=(ml+mr)/2;
    my=(mu+md)/2;
	for (int i=1; i<=4; ++i) {
		for (int j=1; j<=4; ++j) {
			if (segts(k1[i].a,k1[i].b,k2[j].a,k2[j].b)) {
				puts("YES");
				return 0;
			}
		}
	}
	if(mx>=nl&&mx<=nr&&md>=nd&&md<=nu||mx>=nl&&mx<=nr&&mu>=nd&&mu<=nu||ml>=nl&&ml<=nr&&my>=nd&&my<=nu||mr>=nl&&mr<=nr&&my>=nd&&my<=nu)
        cout<<"YES"<<endl;
    else if(nu+nr>=ml+my&&nu<=nr-mx+mu&&nu>=nr-mx+md&&nu+nr<=mr+my||nd+nr>=ml+my&&nd<=nr-mx+mu&&nd>=nr-mx+md&&nd+nr<=mr+my)
        cout<<"YES"<<endl;
    else if(nu+nl>=ml+my&&nu<=nl-mx+mu&&nu>=nl-mx+md&&nu+nl<=mr+my||nd+nl>=ml+my&&nd<=nl-mx+mu&&nd>=nl-mx+md&&nd+nl<=mr+my)
        cout<<"YES"<<endl;
    else if(mx>=nl&&mx<=nr&&my>=nd&&my<=nu)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
	return 0;
}