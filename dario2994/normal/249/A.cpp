#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define eps (1e-8)
#define MAXN
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

int main(){
	double p1,p2,muro,x1,y1,r;
	cin >> p1 >> p2 >> muro >> x1 >> y1 >> r;
	muro-=r;
	//~ if(p2-p1<2*r){
		//~ cout << -1;
		//~ return 0;
	//~ }
	int punto=2*muro-(p1+r);
	int palo=2*muro-p2;
	double assex=-(double)x1*((double)(0-punto)/((double)(punto-y1)));
	double B=assex;
	double A=punto;
	double dist=A*B/sqrt(A*A+B*B);
	double scalata=(dist/A)*(A-(double)palo);
	if(scalata<=r){
		cout << -1;
		return 0;
	}
	cout.precision(30);
	double res=-(double)x1*((double)(muro-punto)/((double)(punto-y1)));
	cout << res;
}