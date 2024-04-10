#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
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

const int N = 200005;

struct fw {
	ll bit[N]={0};

	void ud(int i, int v) {
		for(;i <= N;i+=i&-i)
			bit[i] += v;
	}

	ll qr(int i) {
		return (i)?bit[i]+qr(i-(i&-i)):0;
	}

	ll range(int i, int j) {
		if(j < i) return 0;
		return qr(j) - qr(i-1);
	}

};

int n,k,q;
ll a,b;

ll o[N]={0};
fw B,A;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n >> k >> a >> b >> q;
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			int d,x;
			cin >> d >> x;
			o[d] += x;
			A.ud(d,min(a,o[d])-A.range(d,d));
			B.ud(d,min(b,o[d])-B.range(d,d));
		} else {
			int p;
			cin >> p;
			cout << B.range(1,p-1) + A.range(p+k,n) << "\n";
		}
	}

	return 0;
}