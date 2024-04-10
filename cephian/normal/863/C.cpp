#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int A[3][3], B[3][3];
vector<ll> As;
vector<ll> Bs;
vector<pair<int,int>> type;

int search(int a, int b) {
	auto p = make_pair(a,b);
	for(int i = 0; i < type.size(); ++i)
		if(type[i] == p)
			return i;
	type.push_back(p);
	As.push_back((b+1)%3==a);
	Bs.push_back((a+1)%3==b);
	return search(A[a][b],B[a][b]);
}

int main() {
	ll k;
	int a,b;
	cin >> k >> a >> b,--a,--b;
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			cin >> A[i][j], --A[i][j];
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			cin >> B[i][j], --B[i][j];
	int cut = search(a,b);
	ll A = 0, B = 0;
	for(int i = 0; i < min(k,1LL*cut); ++i) {
		A += As[i];
		B += Bs[i];
	}
	k = max(0LL,k-cut);
	for(int i = cut; i < As.size(); ++i) {
		ll times = k/(As.size()-cut);
		times += i-cut < k%(As.size()-cut);
		A += As[i]*times;
		B += Bs[i]*times;
	}
	cout << A << " " << B << "\n";
}