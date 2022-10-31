#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e6+5;
int loc[N];
int prm[N];
int n;

bool odd() {
	int swaps = 0;
	for(int i = 1; i <= n; ++i) {
		if(prm[i] != i) {
			++swaps;
			int l = loc[i];
			swap(loc[i], loc[prm[i]]);
			swap(prm[i], prm[l]);

		}
	}
	return swaps%2 == 1;
}

int main() {	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> prm[i];
		loc[prm[i]] = i;
	}
	if((n&1) ^ odd()) {
		cout << "Um_nik" << endl;
	} else
		cout << "Petr" << endl;
}