#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 10100;

char sq[NMAX];
char tq[NMAX];

int marks[NMAX][4];
int n;

void run_query(int typ) {
	int sz = 1;
	for(int i=0;i<typ;++i) sz = sz*26;
	for(int q=0;q<n;q+=sz*26) {
		for(int i=0;i<26 && i*sz+q < n;++i) {
			for(int j=0;j<sz && i*sz+j+q <n;++j) {
				sq[i*sz+j+q] = i+'a';
			}
		}
	}
	sq[n] = 0;
	cout << "? " << sq << endl;
	cin >> tq;
	for(int i=0;i<n;++i) {
		marks[i][typ] = tq[i]-'a';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string t;
	cin >> t;
	n = t.size();
	run_query(2);
	run_query(1);
	run_query(0);
	for(int i=0;i<n;++i) {
		int x = (int) (marks[i][2])*26*26;
		//cerr << "!! " << x << endl;
		x += (int) (marks[i][1])*26;
		//cerr << "!! " << x << endl;
		x += (int) (marks[i][0]);
		//cerr << "!! " << x << endl;
		sq[x] = t[i];
	}
	sq[n] = 0;
	cout << "! " << sq << endl;
	
	return 0;
}