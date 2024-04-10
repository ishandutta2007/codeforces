#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
typedef long long LL;

int main(){
	int n;
	double a,d;
	cin >> n >> a >> d;
	double arrival[n];
	int tt[n],vv[n];
	for(int i=0;i<n;i++){
		cin >> tt[i] >> vv[i];
	}
	cout.precision(20);
	for(int i=0;i<n;i++){
		double imp;
		double tx,v;
		tx=tt[i];
		v=vv[i];
		double t=v/a;
		double spazioacc=(a*t*t)/2;
		if(spazioacc>d)imp=sqrt((2*d)/a);
		else imp=t+((d-spazioacc)/v);
		arrival[i]=tx+imp;
		if(i>0 and arrival[i]<arrival[i-1])arrival[i]=arrival[i-1];
		cout << arrival[i] << endl;
	}
}