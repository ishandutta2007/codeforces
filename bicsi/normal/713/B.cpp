/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

const int kMaxN = 500000;

int Left[3], Top[3], Right[3], Bottom[3];

int Query(int a, int b, int c, int d) {
	cout << "? " << a << " " << b << " " << c << " " << d << endl;
	int ans;
	cin >> ans;
	return ans;
}


bool OK() {
	if(Left[1] > Right[1] || Left[2] > Right[2] || Top[1] > Bottom[1] || Top[2] > Bottom[2])
		return false;
	if(Query(Top[1], Left[1], Bottom[1], Right[1]) != 1) return false;
	if(Query(Top[2], Left[2], Bottom[2], Right[2]) != 1) return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// Reminder: query is ? x1 y1 x2 y2
	// Search for top x

	for(int i = 1; i <= 2; ++i) {
		int ans_bottom = 0, ans_right = 0;
		for(int step = (1 << 16); step; step /= 2) {
			if(ans_bottom + step <= n && Query(1, 1, ans_bottom + step, n) < i)
				ans_bottom += step;
			if(ans_right + step <= n && Query(1, 1, n, ans_right + step) < i)
				ans_right += step;
		}
		Bottom[i] = ans_bottom + 1;
		Right[i] = ans_right + 1;
	}

	cerr << "Done part #1" << endl;

	for(int i = 1; i <= 2; ++i) {
		int ans_left = n + 1, ans_top = n + 1;

		for(int step = (1 << 16); step; step /= 2) {
			if(ans_left - step > 0 && Query(1, ans_left - step, n, n) < i)
				ans_left -= step;
			if(ans_top - step > 0 && Query(ans_top - step, 1, n, n) < i)
				ans_top -= step;
		}

		Left[i] = ans_left - 1;
		Top[i] = ans_top - 1;
	}

	cerr << "Done part #2" << endl;

	for(int conf = 0; conf < 16; ++conf) {
		if(conf & 1) swap(Left[1], Left[2]);
		if(conf & 2) swap(Top[1], Top[2]);
		if(conf & 4) swap(Right[1], Right[2]);
		if(conf & 8) swap(Bottom[1], Bottom[2]);
		
		if(OK()) {
			cout << "! ";
			cout << Top[1] << " " << Left[1] << " " << Bottom[1] << " " << Right[1] << ' ';
			cout << Top[2] << " " << Left[2] << " " << Bottom[2] << " " << Right[2] << '\n';
			return 0;
		}

		if(conf & 1) swap(Left[1], Left[2]);
		if(conf & 2) swap(Top[1], Top[2]);
		if(conf & 4) swap(Right[1], Right[2]);
		if(conf & 8) swap(Bottom[1], Bottom[2]);
	}

	assert(false);
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/