#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	int a, b, x;
	string s;
	cin >> a >> b >> x;
	if(a >= b) {
		int xx = 0, yy = 0;
		vi v;
		for(int i=0;i<x+1;i++) {
			if(i&1) yy++;
			else xx++;
			v.PB(1);
		}
		v[0] += a-xx;
		v[1] += b-yy;
		for(int i=0;i<v.size();i++) {
			for(int j=0;j<v[i];j++)
				cout << i%2;
		}
		cout << endl;
	} else {
		swap(a, b);
		int xx = 0, yy = 0;
		vi v;
		for(int i=0;i<x+1;i++) {
			if(i&1) yy++;
			else xx++;
			v.PB(1);
		}
		v[0] += a-xx;
		v[1] += b-yy;
		for(int i=0;i<v.size();i++) {
			for(int j=0;j<v[i];j++)
				cout << (i+1)%2;
		}
		cout << endl;
	}

	
}