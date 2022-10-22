#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
	int n;
	scanf ("%d",&n);
	vector<int> a(n); ll sum = 0; map<ll,int> ree;
	for (auto &au : a) scanf ("%d",&au), sum += au, ++ree[au];
	vector<int> ret;
	for (int i = 0; i < n; i++) {
		if ((sum-a[i])&1) continue;
		int att = ree[(sum-a[i])/2];
		if ((sum-a[i])/2 == a[i]) --att;
		if (att > 0) ret.push_back(i+1);
	}
	printf ("%d\n",ret.size());
	for (int i : ret) printf ("%d ",i);
	printf ("\n");
    return 0;
}