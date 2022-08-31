	/*
Hanit Banga
Problem: 
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

bool correct[26] = {0}, wrong[26] = {0};
char partner[26] = {0};

int main()
{
	string s, t;
	cin >> s >> t;

	int n = s.size();

	for (int i = 0; i < n; ++i)
	{
		if (s[i] == t[i])
		{
			if (wrong[s[i]-'a'])
			{
				cout << -1;
				return 0;
			}

			correct[s[i]-'a'] = true;
		}

		else if (correct[s[i]-'a'] or correct[t[i]-'a'])
		{
			cout << -1;
			return 0;
		}

		else if (partner[s[i]-'a'] and partner[s[i]-'a'] != t[i])
		{
			cout << -1;
			return 0;
		}

		else if (partner[t[i]-'a'] and partner[t[i]-'a'] != s[i])
		{
			cout << -1;
			return 0;
		}

		else 
		{
			partner[s[i]-'a'] = t[i];
			partner[t[i]-'a'] = s[i];
			wrong[s[i]-'a'] = true;
			wrong[t[i]-'a'] = true;
		}
	}

	int k = 0;

	for (int i = 0; i < 26; ++i)
		if (wrong[i])
			++k;

	cout << k/2 << endl;

	for (int i = 0; i < 26; ++i)
		if (wrong[i] and partner[i] > i+'a')
			cout << char(i+'a') << ' ' << partner[i] << endl;
}