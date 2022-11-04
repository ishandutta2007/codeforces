#include <bits/stdc++.h>

using namespace std;

int le[(int)2e5 + 10], ri[(int)2e5 + 10], cnt[(int)2e5 + 10];
vector<pair<pair<int, int>, int> > mas;
int a[(int)2e5 + 10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    fill(le, le + (int)2e5 + 5, n + 10);
    for (int i = 0; i < n; i++)
    {
    	cin >> a[i];
    	le[a[i]] = min(le[a[i]], i);
    	ri[a[i]] = i;
    	cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 0; i <= (int)2e5; i++)
    {
    	if (le[i] <= ri[i])
    	{
    		pair<int, int> p = {le[i], ri[i]};
    		mas.push_back({p, cnt[i]});
    	}
    }
    sort(mas.begin(), mas.end());
    int last = -1;
    int cur = 0;
    for (int i = 0; i < (int)mas.size(); i++)
    {
    	if (mas[i].first.first > last)
    	{
    		ans += cur;
    		cur = mas[i].second;
    	}
    	last = max(last, mas[i].first.second);
    	cur = max(cur, mas[i].second);
    }
    ans += cur;
    cout << n - ans << endl;
    return 0;
}