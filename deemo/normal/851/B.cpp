#include<bits/stdc++.h>

using namespace std;

typedef long double T;
typedef complex<T> point;
const T eps = 1e-13;

T dot(const point &a, const point &b){return real(conj(a)*b);}
T cross(const point &a, const point &b){return imag(conj(a)*b);}

point rotateBy(const point &p, const point &about, double radians){
	return (p - about) * exp(point(0, radians)) + about;
}

point reflect(const point &p, const point &about1, const point &about2){
	point z = p - about1;
	point w = about2 - about1;
	return conj(z/ w)*w + about1;
}

point intersect(const point &a, const point &b, const point &p, const point &q){
	T d1 = cross(p-a, b-a);
	T d2 = cross(q-a, b-a);
	return (d1*q - d2*p)/ (d1-d2);
}

point p[3];

int main(){
	for (int w = 0; w < 3; w++){
		T x, y; cin >> x >> y;
		p[w].real(x);
		p[w].imag(y);
	}
	
	if (abs(cross(p[1]-p[0], p[2]-p[0])) < eps || abs(p[1] - p[0]) != abs(p[2] - p[1]))
		cout << "No\n";
	else
		cout << "Yes\n";
	return 0;
}