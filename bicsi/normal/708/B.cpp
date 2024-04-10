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

#define int long long

const int kMaxN = 500000;
string BAD = "Impossible";

int A[kMaxN], B[kMaxN];
int Cnt[2000000];

int GetNo(int x) {
	assert(x > 0);
	for(int ans = 2; ; ++ans) {
		long long t = 1LL * ans * (ans - 1) / 2;
		if(t > x) return -1;
		if(t == x) return ans;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int zz, zo, oz, oo;
	cin >> zz >> zo >> oz >> oo;
	char one = '1', zero = '0';

	if(zz > oo) {
		swap(zz, oo);
		swap(zo, oz);
		swap(one, zero);
	}

	int zeros, ones;

	if(zz == 0) {
		if(oo == 0) {
			if(oz == 1 && zo == 0) {
				cout << one << zero << endl;
				return 0;
			} 
			if(zo == 1 && oz == 0) {
				cout << zero << one << endl;
				return 0;
			}
			if(zo == 0 && oz == 0) {
				cout << one << endl;
				return 0;
			}

			cout << BAD << endl;
			return 0;
		} else {
			//oo > 0

			if(zo == 0 && oz == 0) {
				zeros = 0;
			} else {
				zeros = 1;
			}
		}
	} else {
		zeros = GetNo(zz);
	}
	ones = GetNo(oo);

	
	int len = GetNo(zz + oz + zo + oo);
	if(len == -1) {
		cout << BAD << endl;
		return 0;
	}

	cerr << "here\n";
	cerr << zeros << " " << ones << '\n';

	if(zeros == -1 || ones == -1) {
		cout << BAD << endl;
		return 0;
	}

	if(zeros + ones != len) {
		cout << BAD << endl;
		return 0;
	}

	if(zeros > ones) {
		swap(zeros, ones);
		swap(oz, zo);
		swap(one, zero);
	}


	int rem = oz;
	for(int i = 0; i < zeros; ++i) {
		 int pos = min(rem, ones);
		Cnt[pos] += 1;
		rem -= pos;
	}

	if(rem != 0) {
		cout << BAD << endl;
		return 0;
	}

	//sort(Pos, Pos + zeros);

	int gotoz = 0, gotzo = 0;

	string ans;

	for(int i = 0; i < ones; ++i) {
		while(Cnt[i]--) {
			ans += zero;
			gotoz += i;
			gotzo += (ones - i);
		}
		ans += one;
	}
	while(Cnt[ones]--) {
		ans += zero;
		gotoz += ones;
	}

	assert(gotoz == oz);

	if(gotoz != oz || gotzo != zo) {
		cout << BAD << endl;
		return 0;
	}
	assert(ans.size() == len);
	cout << ans << endl;
	
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/