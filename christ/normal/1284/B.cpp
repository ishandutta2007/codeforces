#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MN = 1e5+2;
#define all(x) (x).begin(),(x).end()
bool asc[MN];
int mnn[MN], mxx[MN], ac = 0;
vector<int> mx,mn;
int main () {
	int n; ll ans = 0;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) {
		int l;
		scanf ("%d",&l);
		vector<int> s(l);
		mxx[i] = 0, mnn[i] = INT_MAX;
		for (int j = 0; j < l; j++) {
			scanf ("%d",&s[j]);
			if (s[j] > mxx[i]) {
				mxx[i] = s[j];
			}
			if (s[j] < mnn[i]) {
				mnn[i] = s[j];
			}
			if (j && s[j] > s[j-1]) asc[i] = 1;
		}
		if (!asc[i]) {
			mx.push_back(mxx[i]);
			mn.push_back(mnn[i]);
		} else ++ac;
	}
	sort(all(mx)); sort(all(mn));
	for (int i = 1; i <= n; i++) {
		if (asc[i]) {
			ans += n;
			continue;
		}
		ans += mx.size()-(upper_bound(all(mx),mnn[i])-mx.begin())+ac;
	}
	printf ("%lld\n",ans);
	return 0;
}