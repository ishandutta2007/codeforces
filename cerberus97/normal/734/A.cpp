#include <iostream>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int main()
{
	int n;
	cin >> n;

	int a = 0;

	while (n--)
	{
		char s;
		cin >> s;

		if (s == 'A')
			++a;

		else
			--a;
	}

	if (!a)
			cout << "Friendship";

	else if (a > 0)
		cout << "Anton";

	else
		cout << "Danik";
}