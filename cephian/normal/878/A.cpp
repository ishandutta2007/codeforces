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

const int f0 = 2, f1 = 1, nm = 0, op = 3;

int bt[10] = {};

int main() {	
	fio;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string t; int x;
		cin >> t >> x;
		for(int i = 0; i < 10; ++i) {
			int b = (x>>i)&1;
			if(t == "^") {
				if(b) {
					if(bt[i] == f0) bt[i] = f1;
					else if(bt[i] == f1) bt[i] = f0;
					else if(bt[i] == nm) bt[i] = op;
					else if(bt[i] == op) bt[i] = nm;
				}
			} else if(t == "|") {
				if(b) {
					bt[i] = f1;
				}
			} else {
				if(!b) {
					bt[i] = f0;
				}
			}
		}
	}
	int x = 0,a = 1023,o = 0;
	for(int i = 0; i < 10; ++i) {
		if(bt[i] == op) x ^= 1<<i;
		if(bt[i] == f1) o |= 1<<i;
		if(bt[i] == f0) a ^= 1<<i;
	}
	cout << "3\n" << "^ " << x << "\n& " << a << "\n| " << o << "\n";
}