#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int>> used;

int& get(int a, int b) {
	return used[a+401][b+401];
}

void reset() {
	used = vector<vector<int>>(810, vector<int>(810, 0));
}

inline int cross(int a, int b, int c, int d) {
	return a*d-b*c;
}
inline int dot(int a, int b, int c, int d) {
	return a*c+b*d;
}
inline int sgn(int a) {
	return (a == 0 ? 0 : (a > 0 ? 1 : -1));
}
inline bool intersect_helper(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy) {
	int ca = cross(cx-ax, cy-ay, bx-ax, by-ay);
	int da = cross(dx-ax, dy-ay, bx-ax, by-ay);
	return (ca != 0 && da != 0 && sgn(ca) == -sgn(da) );
}

/*
 *
 * |\  /|
 * | \/ |
 * | /\ |
 * |/  \|
 */ 

bool solve_for(vector<int>& s1, vector<int>& s2) {
	reset();

	int minx1 = 200, maxx1 = -200, miny1 = 200, maxy1 = -200;
	int minx2 = 200, maxx2 = -200, miny2 = 200, maxy2 = -200;
	for(int i=0;i<4;++i) {
		minx1 = min(minx1, s1[i*2]);
		maxx1 = max(maxx1, s1[i*2]);
		miny1 = min(miny1, s1[i*2+1]);
		maxy1 = max(maxy1, s1[i*2+1]);
		minx2 = min(minx2, s2[i*2]);
		maxx2 = max(maxx2, s2[i*2]);
		miny2 = min(miny2, s2[i*2+1]);
		maxy2 = max(maxy2, s2[i*2+1]);
	}
	int avgx2 = (minx2+maxx2)/2;
	int avgy2 = (miny2+maxy2)/2;
	for(int i=minx1; i<maxx1;++i) {
		for(int j=miny1;j<maxy1;++j) {
			get(i, j) = 1;
			//////cerr << "SET " << i << " " << j << endl;
		}
	}
	vector<pii> options;
	options.push_back(pii(avgx2		, miny2     ));
	options.push_back(pii(avgx2-1   , miny2     ));
	options.push_back(pii(avgx2		, maxy2-1   ));
	options.push_back(pii(avgx2-1	, maxy2-1   ));
	options.push_back(pii(maxx2-1   , avgy2     ));
	options.push_back(pii(maxx2-1   , avgy2-1   ));
	options.push_back(pii(minx2		, avgy2     ));
	options.push_back(pii(minx2		, avgy2-1   ));
	for(pii o : options) {
		if(get(o.first, o.second)) {
			//cerr << "!!!" << endl;
			return true;
		}
	}
	for(int i=0;i<4;++i) {
		for(int j=0;j<4;++j) {
			if(cross(s1[2*i] -s1[(2*i+2)%8], s1[2*i+1] - s1[(2*i+3)%8],
					 s2[2*j] -s1[(2*i+2)%8], s2[2*j+1] - s1[(2*i+3)%8]) == 0) {
				int dp = dot(s1[2*i] -s1[(2*i+2)%8], s1[2*i+1] - s1[(2*i+3)%8],
							 s2[2*j] -s1[(2*i+2)%8], s2[2*j+1] - s1[(2*i+3)%8]);
				int self = dot(s1[2*i] -s1[(2*i+2)%8], s1[2*i+1] - s1[(2*i+3)%8],s1[2*i] -s1[(2*i+2)%8], s1[2*i+1] - s1[(2*i+3)%8]);
				////cerr << "DP VS SELF ij " << i << j << ": " << dp << " " << self << endl;
				if(dp >= 0 && dp <= self) {
					//cerr << "!!" << endl;
					return true;
				}
			}
		}
	}

	for(int i=0;i<4;++i) {
		for(int j=0;j<4;++j) {
			if(intersect_helper(s1[2*i], s1[2*i+1], s1[(2*i+2)%8], s1[(2*i+3)%8],
							    s2[2*j], s2[2*j+1], s2[(2*j+2)%8], s2[(2*j+3)%8])
			&& intersect_helper(s2[2*j], s2[2*j+1], s2[(2*j+2)%8], s2[(2*j+3)%8],
							    s1[2*i], s1[2*i+1], s1[(2*i+2)%8], s1[(2*i+3)%8])) {
				//cerr << "INTERSECT " << s1[2*i]<< ' ' << s1[2*i+1]<< ' ' << s1[(2*i+2)%8]<< ' ' << s1[(2*i+3)%8]<< ' ' <<s2[2*j]<< ' ' << s2[2*j+1]<< ' ' << s2[(2*j+2)%8]<< ' ' << s2[(2*j+3)*8] << endl;
				return true;
			}
		}
	}

	return false;
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	vector<int> s1(8);
	vector<int> s2(8);
	for(int& ii : s1) cin >> ii;
	for(int& ii : s2) cin >> ii;
	for(int i=0;i<8;++i) {
		s1[i]*= 2;
		s2[i]*= 2;
	}
	if(solve_for(s1, s2)) {
		cout << "YES" << endl;
		return 0;
	}

	vector<int> s3(8);
	vector<int> s4(8);
	for(int i=0;i<4;++i) {
		s3[i*2] = s1[i*2]+s1[i*2+1];
		s3[i*2+1] = -s1[i*2]+s1[i*2+1];
		s4[i*2] = s2[i*2]+s2[i*2+1];
		s4[i*2+1] = -s2[i*2]+s2[i*2+1];
	}

	if(solve_for(s4, s3)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}