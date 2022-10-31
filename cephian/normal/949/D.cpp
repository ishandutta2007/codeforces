#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int n, d, b;
int a[N];
int A[N];
int B[N];
int lnum = 0;
int rnum = 0;


bool ok(int miss) {
	for(int i = 1; i <= n; ++i) {
		A[i] = a[i];
	}

	int ltgt = 1+miss;
	int rtgt = n-miss;
	int lsrc = 1;
	int rsrc = n;

	fill(B+1, B+n+1, 0);
	fill(B+ltgt, B+rtgt+1, b);

		//for(int i = 1; i <= n; ++i) cout << A[i] << " ";
		//cout << "\n";
		//for(int i = 1; i <= n; ++i) cout << B[i] << " ";
		//cout << endl;
		//cout << lsrc << " --> " << ltgt << " and " << rsrc << " --> " << rtgt << endl;
		//cout << "-----\n";

	while(true) {
		bool moved = false;
		// move on left side
		if(lsrc <= n && ltgt <= n) {
			if( (abs(lsrc-ltgt)+d-1)/d > min(ltgt, n-ltgt+1))
				++lsrc;
			else {
				int move = min(B[ltgt], A[lsrc]);
				A[lsrc] -= move;
				B[ltgt] -= move;
				if(A[lsrc] == 0) ++lsrc;
				if(B[ltgt] == 0) ++ltgt;
			}
			moved = true;
		}
		// move on right side
		if(rsrc >= 1 && rtgt >= 1) {
			if( (abs(rtgt-rsrc)+d-1)/d > min(rtgt, n-rtgt+1))
				--rsrc;
			else {
				int move = min(B[rtgt], A[rsrc]);
				A[rsrc] -= move;
				B[rtgt] -= move;
				if(A[rsrc] == 0) --rsrc;
				if(B[rtgt] == 0) --rtgt;
			}
			moved = true;
		}
		if(!moved) break;

		//for(int i = 1; i <= n; ++i) cout << A[i] << " ";
		//cout << "\n";
		//for(int i = 1; i <= n; ++i) cout << B[i] << " ";
		//cout << endl;
		//cout << lsrc << " --> " << ltgt << " and " << rsrc << " --> " << rtgt << endl;
		//cout << "-----\n";
	}

	for(int i = 1; i <= n; ++i)
		if(B[i] != 0)
			return false;

	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
	cin >> n >> d >> b;

	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	int lo = -1, hi = (n+1)/2;
	while(hi-lo-1) {
		int md = (lo+hi)/2;
		if(ok(md)) {
			hi = md;
		}
		else {
			lo = md;
		}
	}
	cout << hi << "\n";
}