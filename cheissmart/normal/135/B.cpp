#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

struct Point{
	int x, y;
	Point(int _x=0, int _y=0) {
		x = _x, y = _y;
	}
} a[10];

struct Vec{
	int x, y;
	Vec(Point p1, Point p2) {
		x = p1.x-p2.x;
		y = p1.y-p2.y;
	}
	int cross(Vec p) {
		return x * p.x + y * p.y;
	}
	int len2() {
		return x*x + y*y;
	}
};

bool sq(Point p1, Point p2, Point p3, Point p4) {
	{
		Vec v1(p1, p2), v2(p1, p3), v3(p4, p2), v4(p4, p3);
		if(v1.len2() == v2.len2() && v2.len2() == v3.len2() && v3.len2() == v4.len2() && v1.cross(v2) == 0 && v3.cross(v4) == 0)
			return true;
	}
	swap(p2, p4);
	{
		Vec v1(p1, p2), v2(p1, p3), v3(p4, p2), v4(p4, p3);
		if(v1.len2() == v2.len2() && v2.len2() == v3.len2() && v3.len2() == v4.len2() && v1.cross(v2) == 0 && v3.cross(v4) == 0)
			return true;
	}
	return false;
}

bool rec(Point p1, Point p2, Point p3, Point p4) {
	{
		Vec v1(p1, p2), v2(p1, p3), v3(p4, p2), v4(p4, p3);
		if(v2.len2() == v3.len2() && v1.len2() == v4.len2() && v1.cross(v2) == 0 && v3.cross(v4) == 0)
			return true;
	}
	swap(p2, p4);
	{
		Vec v1(p1, p2), v2(p1, p3), v3(p4, p2), v4(p4, p3);
		if(v2.len2() == v3.len2() && v1.len2() == v4.len2() && v1.cross(v2) == 0 && v3.cross(v4) == 0)
			return true;
	}
	return false;
}

int main()
{
	IO_OP;
	
	for(int i=0;i<8;i++)
		cin >> a[i].x >> a[i].y;
	vi v = {0, 1, 2, 3, 4, 5, 6, 7};
	
	do{
		if(sq(a[v[0]], a[v[1]], a[v[2]], a[v[3]]) && rec(a[v[4]], a[v[5]], a[v[6]], a[v[7]])) {
			cout << "YES" << endl;
			for(int i=0;i<4;i++) cout << v[i]+1 << " \n"[i==3];
			for(int i=4;i<8;i++) cout << v[i]+1 << " \n"[i==7];
			return 0;
		}
	} while(next_permutation(v.begin(), v.end()));
	cout << "NO" << endl;
}