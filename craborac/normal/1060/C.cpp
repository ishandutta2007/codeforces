#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long a[2010], b[2010];
vector<pair<long long, int> > v;
int mx[2000 * 2000 + 10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        long long s = 0;
        for (int j = i; j >= 0; j--)
        {

            s += a[j];
            v.push_back({s, i - j + 1});
        }
    }
    sort(v.begin(), v.end());
    mx[0] = v[0].second;
    for (int i = 1; i < (int)v.size(); i++)
    {
        mx[i] = max(mx[i - 1], v[i].second);
    }
    for (int i = 0; i < (int)v.size(); i++)
    {
        //cout << v[i].first << " " << v[i].second << " " << mx[i] << endl;
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    long long x;
    cin >> x;
    for (int i = 0; i < m; i++)
    {
        long long s = 0;
        for (int j = i; j < m; j++)
        {
            s += b[j];
            pair<long long, int> p = {x / s, n};
            int q = upper_bound(v.begin(), v.end(), p) - v.begin();
            q--;
            //cout << i << " " << j << " " << s << " " << q << " " << mx[q] << endl;
            if (q >= 0)
                ans = max(ans, mx[q] * (j - i + 1));
        }
    }
    cout << ans << endl;
	return 0;
}