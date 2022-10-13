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

const int kMod = 1e9 + 7;
const int kInv2 = (kMod + 1) / 2;

long long Aux[3][3];
void inm(int A[3][3], int B[3][3], int R[3][3]) {
	for(int i = 0; i < 3; ++i) 
		for(int j = 0; j < 3; ++j) {
			Aux[i][j] = 0;
			for(int k = 0; k < 3; ++k) {
				Aux[i][j] += 1LL * A[i][k] * B[k][j];
			}
		}

	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			R[i][j] = Aux[i][j] % kMod;
}

int lgpow(int A[3][3], long long e) {
	int R[3][3] = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};

	while(e) {
		if(e % 2) {
			inm(R, A, R);
		}
		inm(A, A, A);
		e /= 2;
	}

	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			A[i][j] = R[i][j];
}

void lgpow(int &b, long long e) {
	int r = 1;
	while(e) {
		if(e % 2) {
			r = 1LL * r * b % kMod;
		}
		b = 1LL * b * b % kMod;
		e /= 2;
	}
	b = r;
}

int Old[3], Prob[3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int Mat[3][3] = {
		{1, 1, 0},
		{1, 0, 1},
		{0, 1, 1}
	};

	int n;
	long long val;
	int dwn = 2;

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%I64d", &val);
		val %= (kMod - 1);
		lgpow(Mat, val);
		lgpow(dwn, val);
	}

	cout << 1LL * Mat[1][1] * kInv2 % kMod;
	cout << "/";
	cout << 1LL * dwn * kInv2 % kMod;
	cout << endl;


}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/