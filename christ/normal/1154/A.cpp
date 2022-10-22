#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
	vector<int> a(4);
	for (auto &au : a) scanf ("%d",&au);
	sort(all(a));
	for (int i = 0; i < 3; i++) printf ("%d ",a[3]-a[i]);
	printf ("\n");
    return 0;
}