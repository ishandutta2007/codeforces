#include<bits/stdc++.h>

using namespace std;

typedef long double T;
typedef complex<T> point;

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

point readP(){
	int x, y; cin >> x >> y;
	point ret(x, y);
	return ret;
}

int main(){
	cout << fixed << setprecision(12);
	int r;
	cin >> r;
	point x = readP(), y = readP();
	if (abs(y - x) > r)
		cout << x.real() << " " << x.imag() << " " << r << "\n";
	else{
		T newR = r + abs(y - x);
		newR /= 2;
		point res = y - x;
		res = polar(abs(res) - newR, arg(res));
		res += x;
		cout << res.real() << " " << res.imag() << " " << newR << "\n";
	}
	return 0;
}