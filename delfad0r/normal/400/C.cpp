#include <cstdio>
#include <iostream>

int N, M, X, Y, Z, P;

struct point {
	int n, m;
	int myN, myM;
	point(int n_ = 0, int m_ = 0, int myN_ = 0, int myM_ = 0) : n(n_), m(m_), myN(myN_), myM(myM_) { }
};

void rotatecw(point & p, int l) {	//for ccw rotation, just pass a negative number
	switch((l % 4 + 4) % 4) {
		case 0:
		break;
		case 1:
		p = point(p.m, p.myN + 1 - p.n, p.myM, p.myN);
		break;
		case 2:
		p = point(p.myN + 1 - p.n, p.myM + 1 - p.m, p.myN, p.myM);
		break;
		case 3:
		p = point(p.myM + 1 - p.m, p.n, p.myM, p.myN);
		break;
	}
}

void mirror(point & p, int l) {
	switch(l % 2) {
		case 0:
		break;
		case 1:
		p = point(p.n, p.myM + 1 - p.m, p.myN, p.myM);
		break;
	}
}

int main() {
	point candy;
	
	std::ios_base::sync_with_stdio(false);
	std::cin >> N >> M >> X >> Y >> Z >> P;
	while(--P >= 0) {
		candy.myN = N;
		candy.myM = M;
		std::cin >> candy.n >> candy.m;
		rotatecw(candy, X);
		mirror(candy, Y);
		rotatecw(candy, -Z);
		std::cout << candy.n << ' ' << candy.m << '\n';
	}
}