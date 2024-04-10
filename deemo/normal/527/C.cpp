#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<cmath>

using namespace std;

typedef long long ll;
#define pb(x) insert(x)

const int max_n = 2e5 + 200;

int n, w, h;
set<int>	ver, hor;
vector<int>	a, b;
vector<pair<int, int>>	q;
vector<ll>	ans;

int main(){
	scanf("%d%d%d", &w, &h, &n);
	q.resize(n);
	ver.pb(0);	ver.pb(w);
	hor.pb(0);	hor.pb(h);
	
	for (int i = 0; i < n; i++){
		char c;
		int temp;
		scanf("%1s%d", &c, &temp);
		if (c == 'H')	hor.pb(temp), q[i] = {0, temp};
		else	ver.pb(temp), q[i] = {1, temp};
	}

	int maxv = 0, maxh = 0;
	set<int>::iterator it = ver.begin(), tm = ver.end(), f;
	tm--;
	while (it != tm){
		f = it, f++;
		maxv = max(maxv, *f - *it);
		it = f;
	}

	it = hor.begin(), tm = hor.end();
	tm--;
	while (it != tm){
		f = it, f++;
		maxh = max(maxh, *f - *it);
		it = f;
	}
	ans.push_back(ll(maxv) * maxh);

	for (int i = n - 1;i > 0; i--){
		if (q[i].first == 0){//hor
			maxh = max(maxh, *hor.upper_bound(q[i].second) - 
				({it = hor.lower_bound(q[i].second); it--; *it;}));
			hor.erase(q[i].second);
		}
		if (q[i].first == 1){//ver
			maxv = max(maxv, *ver.upper_bound(q[i].second) - 
				({it = ver.lower_bound(q[i].second); it--; *it;}));
			ver.erase(q[i].second);
		}
		ans.push_back(ll(maxv) * maxh);
	}

	for (int i = n - 1; i >= 0; i--)
		printf("%I64d\n", ans[i]);

	return 0;
}