#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 200005, mod = 1e9 + 7, pod = (1 << 18), inf = 1e9 + 9;

tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema[pod * 2];

int n;
int q;
int a, b;
int t[nax];
ll ans;


void Add(int pos, int x) {
	pos += pod;
	siema[pos].insert(x);
	pos /= 2;
	while(pos)
	{
		siema[pos].insert(x);
		pos /= 2;
	}
}

void Erase(int pos, int x) {
	pos += pod;
	siema[pos].erase(x);
	pos /= 2;
	while(pos)
	{
		siema[pos].erase(x);
		pos /= 2;
	}
}

int Less(int x, int y, int val, int w = 1, int le = 0, int pr = pod - 1)
{
	if(y >= pr && le >= x)
	{
		return siema[w].order_of_key(val);
	}
	int res = 0;
	int mid = (le + pr) / 2;
	if(mid >= x)
		res += Less(x, y, val, w * 2, le, mid);
	if(y > mid)
		res += Less(x, y, val, w * 2 + 1, mid + 1, pr);
	return res;
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> q;
	for(int i = 1; n >= i; ++i)
		Add(i, i), t[i] = i;
	
	while(q--)
	{
		cin >> a >> b;
		if(a > b)
			swap(a, b);
		if(t[a] > t[b])
			--ans;
		else if(t[a] < t[b])
			++ans;
		Erase(a, t[a]);
		Erase(b, t[b]);
		Add(b, t[a]);
		Add(a, t[b]);
		if(abs(a - b) <= 1) {
			swap(t[a], t[b]);
			cout << ans << endl;
			continue;
		}
		
		int A = Less(a + 1, b - 1, t[a]);
		int B = Less(a + 1, b - 1, t[b]);
		ans += 2 * B - 2 * A;
		cout << ans << endl;
		swap(t[a], t[b]);
	}
	
	
	
	
		

    return 0;
}