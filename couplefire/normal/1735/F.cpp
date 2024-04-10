#include <bits/stdc++.h>

using namespace std;
	
typedef long double ld;
	
struct Vector {
	ld x, y;
};

Vector operator * (ld b, Vector a) {
	return {a.x * b, a.y * b};
}


Vector operator * (Vector a, ld b) {
	return {a.x * b, a.y * b};
}

Vector operator / (Vector a, ld b) {
	return {a.x / b, a.y / b};
}

Vector operator + (Vector a, Vector b) {
	return {a.x + b.x, a.y + b.y};
}

Vector operator - (Vector a, Vector b) {
	return {a.x - b.x, a.y - b.y};
}

ld get_norm(Vector a) {
	return sqrt(a.x * a.x + a.y * a.y);
}

Vector normalize(Vector a) {
	return a / get_norm(a);
}

bool operator < (Vector a, Vector b) {
	return atan2(a.y, a.x) < atan2(b.y, b.x);
}

const ld eps = 1e-14;

int main() {
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
	
	int tests;
	cin >> tests;
	for (int tc = 1; tc <= tests; tc++) {
		int n, c1, c2;
		cin >> n >> c1 >> c2;
		 
		vector<int> pp(n), qq(n);
		for (int i = 0; i < n; i++) cin >> pp[i];
		for (int i = 0; i < n; i++) cin >> qq[i];
		
		Vector first = {0, (ld) c2};
		Vector last = {(ld) c1, 0};

		
		
		multiset<Vector> sv;
		sv.insert(Vector{(ld) c1, 0});
		sv.insert(Vector{0, (ld) c2});
		
	
		for (int i = 0; i < n; i++) {
			
			ld p = pp[i], q = qq[i];
			
			Vector v = {p, q};
			sv.insert(2 * v);

			first = first + Vector{-p, +q};
			last = last + Vector{+p, -q};

			while (first.x < -eps) {
				auto it = sv.begin();
				Vector guy = *it;
				if (first.x + guy.x < -eps) {
					sv.erase(it);
					first = first + Vector{guy.x, -guy.y};
					continue;
				}
				ld t = -first.x / guy.x;
				sv.erase(it);
				first = first + t * Vector{guy.x, -guy.y};
				sv.insert((1 - t) * guy);
			}			
			while (last.y < -eps) {
				auto it = sv.end();
				it--;
				Vector guy = *it;
				if (last.y + guy.y < -eps) {
					sv.erase(it);
					last = last - Vector{guy.x, -guy.y};
					continue;
				}
				ld t = -last.y / guy.y;
				sv.erase(it);
				last = last - t * Vector{guy.x, -guy.y};
				sv.insert((1 - t) * guy);

			}
			cout << fixed << setprecision(6) << last.x << "\n";
		}
	}
	

}