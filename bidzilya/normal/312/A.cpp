#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, int> pii;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	cin.ignore();
	for (int i=0; i<n; i++)
	{
		string s;
		getline(cin, s);
		int l = s.length();
		bool isfr = (l >= 5 && s[l-1]=='.' && s[l-2]=='a' && s[l-3]=='l' &&
			s[l-4]=='a' && s[l-5]=='l');
		bool isra = (l >= 5 && s[0]=='m' && s[1]=='i' && s[2]=='a' && s[3]=='o' && s[4]=='.');
		if (isfr && !isra)
			cout << "Freda's" << endl;
		else
		if (isra && !isfr)
			cout << "Rainbow's" << endl;
		else
			cout << "OMG>.< I don't know!" << endl;
	}
	return 0;
}