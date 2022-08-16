#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, INF = 2147483647;

string days[7] =  {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int f(string s)
{
	for (int i = 0; i < 7; ++i)
		if (s == days[i])
			return i;

	return -1;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	int n1 = f(s1), n2 = f(s2);

	if (n2 < n1)
		n2 += 7;

	int diff = n2 - n1;

	if (diff == 0 or diff == 2 or diff == 3)
		cout << "YES";

	else
		cout << "NO";
}