#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
bool b[105];
vector<pair<int, int> > v;
vector<pair<int, int> > ans;

bool ready()
{
	for (int i = 1; i <= n; i++) if (!b[i]) return false;
	return true;
}

bool emp()
{
	for (int i = 0; i < n; i++) if (b[v[i].second] && v[i].first > 0) return false;
	return true;
}

int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		v[i].second = i + 1;
	}
	sort(v.rbegin(), v.rend());
	int k = 0;
	while (v[k].second != 1) k++;
	b[1] = 1;
	while (!ready() && !emp())
	{
		for (int i = 0; i < n && v[k].first>0; i++)
		{
			if (b[v[i].second] == 0)
			{
				b[v[i].second] = 1;
				v[k].first--;
				ans.push_back(make_pair(v[k].second, v[i].second));
			}
		}
		k = 0;
		while (k < n && (!b[v[k].second] || v[k].first==0)) k++;
	}
	if (ready())
	{
		cout << ans.size() << endl;
		for (auto p : ans) cout << p.first << " " << p.second << endl;
	}
	else cout << -1;
}