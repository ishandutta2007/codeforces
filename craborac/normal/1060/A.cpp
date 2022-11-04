#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int cnt = 0;
	for (int i = 0; i < n; i++)
    {
        if (s[i] == '8')
            cnt++;
    }
    cout << min(cnt, n / 11) << endl;
	return 0;
}