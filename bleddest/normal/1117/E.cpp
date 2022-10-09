#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	string t;
	cin >> t;
	int n = t.size();
	string s1(n, 'a'), s2(n, 'a'), s3(n, 'a');
	for(int i = 0; i < n; i++)
	{
		s1[i] = char('a' + (i % 26));
		s2[i] = char('a' + ((i / 26) % 26));
		s3[i] = char('a' + ((i / 26 / 26) % 26));
	}
	cout << "? " << s1 << endl;
	cout.flush();
	string t1;
	cin >> t1;
	cout << "? " << s2 << endl;
	cout.flush();
	string t2;
	cin >> t2;
	cout << "? " << s3 << endl;
	cout.flush();
	string t3;
	cin >> t3;
	vector<int> p(n);
	for(int i = 0; i < n; i++)
		p[i] = (t1[i] - 'a') + (t2[i] - 'a') * 26 + (t3[i] - 'a') * 26 * 26;
	string s(n, 'a');
	for(int i = 0; i < n; i++)
		s[p[i]] = t[i];
	cout << "! " << s << endl;
	return 0;
}