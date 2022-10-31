#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int B = 1005;
int vars,bits;

//dynamic num
struct number {
	bool T[B];
	bool F[B];
};

ostream& operator<< (ostream& o, const number& a) {
	for(int i = 0; i < bits; ++i)
		o << "(" << a.T[i] << "|" << a.F[i] << ")";
	return o;
}

struct operation {
	bool t[2][2];

	operation(int a, int b, int c, int d) {
		t[0][0] = a;
		t[0][1] = b;
		t[1][0] = c;
		t[1][1] = d;
	}

	bool apply(bool a, bool b) const {
		return t[a][b];
	}
};



number combine(const number& A,const operation& O,const number& B) {
	number R;
	for(int i = 0; i < bits; ++i) {
		R.T[i] = O.apply(A.T[i],B.T[i]);
		R.F[i] = O.apply(A.F[i],B.F[i]);
	}
	return R;
}

number make(const string& s) {
	number R;
	for(int i = 0; i < bits; ++i) {
		R.T[i] = R.F[i] = s[i]=='1';
	}
	return R;
}

number Q;
map<string, number> M;
operation XOR(0,1,1,0),AND(0,0,0,1),OR(0,1,1,1);
int pos[1005],neg[1005];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> vars >> bits;
	fill(Q.T,Q.T+bits,1);
	fill(Q.F,Q.F+bits,0);
	M["?"] = Q;
	for(int i = 0; i < vars; ++i) {
		string name,t,a1;
		cin >> name >> t >> a1;
		if(a1[0] == '0' || a1[0] == '1') {
			M[name] = make(a1);
		} else {
			string op,a2;
			cin >> op >> a2;
			if(op == "XOR") M[name] = combine(M[a1],XOR,M[a2]);
			if(op == "AND") M[name] = combine(M[a1],AND,M[a2]);
			if(op == "OR") M[name] = combine(M[a1],OR,M[a2]);
		}
	}
	for(auto p : M) {
		if(p.first == "?") continue;
		for(int i = 0; i < bits; ++i) {
			pos[i] += p.second.T[i];
			neg[i] += p.second.F[i];
		}
	}
	for(int i = 0; i < bits; ++i) {
		cout << ((pos[i] < neg[i])?1:0);
	}
	cout << "\n";
	for(int i = 0; i < bits; ++i) {
		cout << ((pos[i] > neg[i])?1:0);
	}
	cout << "\n";
	return 0;
}