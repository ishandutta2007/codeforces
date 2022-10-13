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

int Mat[50][50];
int n, m;

void Swap(int a, int b) {
	for(int i = 1; i <= n; ++i)
		swap(Mat[i][a], Mat[i][b]);
}

bool OK(int i) {
	auto *V = Mat[i];

	int cnt = 0;
	for(int i = 1; i <= m; ++i) {
		if(V[i] != i)
			cnt += 1;
	}

	assert(cnt != 1);
	return cnt <= 2;
}

bool OK() {
	for(int i = 1; i <= n; ++i)
		if(!OK(i))
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cin >> Mat[i][j];
		}
	}

	for(int a = 1; a <= m; ++a) {
		for(int b = a; b <= m; ++b) {
			Swap(a, b);
			if(OK()) {
				cout << "YES\n";
				return 0;
			}
			Swap(a, b);
		}
	}

	cout << "NO\n";
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/