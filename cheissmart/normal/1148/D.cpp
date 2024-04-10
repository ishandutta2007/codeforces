#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[300005], b[300005];
vector<int> v1, v2;

bool cmp1(int i, int j) {
	return b[i] > b[j];
}

bool cmp2(int i, int j) {
	return a[i] < a[j];
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i] >> b[i];
		if(a[i] < b[i]) {
			v1.PB(i);
		} else {
			v2.PB(i);
		}
	}
	sort(v1.begin(), v1.end(), cmp1);
	sort(v2.begin(), v2.end(), cmp2);
	if(v1.size() > v2.size()) {
		cout << v1.size() << endl;
		for(auto e:v1)
			cout << e << " ";
	} else {
		cout << v2.size() << endl;
		for(auto e:v2)
			cout << e << " ";
	}
}