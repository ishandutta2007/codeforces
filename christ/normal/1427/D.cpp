#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 5e5 + 5;
int main() {
	int n;
	scanf ("%d",&n);
	if (n==1) return !printf ("0\n");
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
	}
	vector<vector<int>> ret; int par = 0;
	for (int i = 1; i < n; i++) {
		int pos = -1;
		for (int j = 1; j <= n; j++) if (a[j] == i) pos = j;
		vector<int> go;
		for (int j = 1; j < i; j++) go.push_back(1);
		go.push_back(pos-i+1);
		for (int i = pos+1; i <= n; i++) go.push_back(1);
		if (par ^ (i&1^1)) reverse(go.begin(),go.end());
		if ((int)go.size() > 1) {
			ret.push_back(go);
		} else {
			par ^= 1;
			ret.push_back({});
			for (int i = 1; i <= n; i++) ret.back().push_back(1);
		}
		reverse(a.begin()+i,a.begin()+pos+1);
	}
	if (par ^ (n&1^1)) {
		ret.push_back({});
		for (int i = 1; i <= n; i++) ret.back().push_back(1);
	}
	printf ("%d\n",(int)ret.size());
	for (vector<int> &v : ret) {
		printf ("%d ",(int)v.size());
		for (int i : v) printf ("%d ",i);
		printf ("\n");
	}
	return 0;
}