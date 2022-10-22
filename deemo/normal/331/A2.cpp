#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 10;

int n, vec[MAXN], sec[MAXN];
bool mark[MAXN];
ll p[MAXN];
vector<int>	gec[MAXN], tt;
map<int, int>	mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i], sec[i] = vec[i];
	sort(sec, sec + n);
	int t = unique(sec, sec + n) - sec;
	for (int i = 0; i < t; i++)
		mp[sec[i]] = i;
	for (int i = 0; i < n; i++){
		gec[mp[vec[i]]].push_back(i);
		p[i + 1] = p[i] + (vec[i] > 0?vec[i]:0);
	}

	ll mx = -1e18;	int ind = -1;
	for (int i = 0; i < n; i++){
		int v = mp[vec[i]];
		if (i == gec[v].back())	continue;
		ll ret = 2 * vec[i];
		ret += p[gec[v].back()]	- p[i + 1];

		if (ret > mx){
			mx = ret;
			ind = i;
		}
	}

	cout << mx << " ";
	mark[ind] = mark[gec[mp[vec[ind]]].back()] = 1;
	for (int i = ind + 1; i < gec[mp[vec[ind]]].back(); i++)
		if (vec[i] >= 0)	mark[i] = 1;
	for (int i = 0; i < n; i++)
		if (!mark[i])	tt.push_back(i);
	cout << tt.size() << "\n";
	for (int u:tt)
		cout << u + 1 << " ";
	cout << "\n";
	return	0;
}