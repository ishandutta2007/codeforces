#include<bits/stdc++.h>
using namespace std;
struct Point{long double px,py;};
complex<long double> reflection(complex<long double> a, complex<long double> b) {
	return conj(b / a) * a;
}
long double dst(Point a,Point b,Point c){
	complex<long double> P1(a.px,a.py);
	complex<long double> P2(b.px,b.py);
	complex<long double> P3(c.px,c.py);
	auto ans=reflection(P2-P1,P3-P1)+P1;
	//cout<<P1.real()<<' '<<P1.imag()<<' '<<P2.real()<<' '<<P2.imag()<<' '<<P3.real()<<' '<<P3.imag()<<' '<<ans.real()<<' '<<ans.imag()<<endl;
	return sqrtl(powl(ans.real()-c.px,2.0l)+powl(ans.imag()-c.py,2.0l));
}
int main(){
	Point p[1000];int n;
	cin>>n;for(int i=0;i<n;i++)cin>>p[i].px>>p[i].py;
	long double maxn=1e20;
	for(int i=0;i<n;i++)maxn=min(maxn,dst(p[(i+n-1)%n],p[(i+n+1)%n],p[i]));
	printf("%.12Lf\n",maxn/4.0l);
	return 0;
}