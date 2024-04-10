#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
int n;
string s[50005];
int len[50005];
bool cmp(string a, string b)
{
	return a + b < b + a;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; n >= i; ++i)
		cin >> s[i];
	sort(s + 1, s + n + 1, cmp);
	for(int i = 1; n >= i; ++i)
		cout << s[i];
		
		
	return 0;
}