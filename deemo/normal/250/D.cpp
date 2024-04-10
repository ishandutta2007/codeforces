#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef double ld;

const int MAXN = 1e5 + 10;

int n, m;
ld a, b;
int sec[MAXN], l[MAXN];
pair<int, int>	vec[MAXN];

ld dis(ll x, ll y, ll xx, ll yy){
	ll ret = (x - xx) * (x - xx);
	ret += (y - yy) * (y - yy);
	return	sqrt(ret);
}	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> a >> b;
	for (int i = 0; i < n; i++){
		cin >> vec[i].first;
		vec[i].second = i;
	}
	sort(vec, vec + n);

	int a1 = -1, a2 = -1;
	ld mini = 1e18 + 4;
	for (int j = 0; j < m; j++)
		cin >> sec[j];
	for (int j = 0; j < m; j++)
		cin >> l[j];
	
	for (int j = 0; j < m; j++){
		ld pnt = a/b * sec[j];

		int pos = lower_bound(vec, vec + n, make_pair(int(ceil(pnt)), -100)) - vec;

		int z;
		if (pos == n)	z = vec[pos - 1].second;
		else if (pos == 0)	z = vec[pos].second;
		else{
			if (dis(0, 0, a, vec[pos].first) + dis(a, vec[pos].first, b, sec[j]) < dis(0, 0, a, vec[pos - 1].first) + dis(a, vec[pos - 1].first, b, sec[j]))	
				z = vec[pos].second;
			else
				z = vec[pos - 1].second;
		}

		ld te = dis(0, 0, a, vec[z].first) + dis(a, vec[z].first, b, sec[j]) + l[j];
		if (mini > te){
			mini = te;
			a1 = z;
			a2 = j;
		}
	}
	cout << a1 + 1 << " " << a2 + 1 << endl;
	return 0;
}