#include <bits/stdc++.h>

using namespace std;

int c[(int)3e5 + 10], answ[(int)3e5 + 10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    set<pair<int, int> > se;
    long long sum = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
    	cin >> c[i];
    	if (i < m)
    	{
    		ans += (long long) (m - i) * c[i];
    		sum += c[i];
    		se.insert({c[i], i});
    	}
    }
    for (int i = m; i < n; i++)
    {
        se.insert({c[i], i});
        sum += c[i];
        auto q = se.end();
        q--;
        sum -= q->first;
        answ[q->second] = i + 1;
        se.erase(q);
        ans += sum;
    }
    for (int i = n; i < n + m; i++)
    {
        auto q = se.end();
        q--;
        sum -= q->first;
        answ[q->second] = i + 1;
        se.erase(q);
        ans += sum;
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
        cout << answ[i] << " ";
    return 0;
}