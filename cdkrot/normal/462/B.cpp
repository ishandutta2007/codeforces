#include <iostream>
#include <algorithm>

using std::cin; using std::cout; using std::endl;

template <typename T>
T sqr(T a)
{
	return a * a;
}

int main()
{
	int table[26];
	std::fill(table, table + 26, 0);
	int n, k;
	cin >> n >> k;
	
	while (cin.peek() == '\n')
		cin.get();
	
	for (int i = 0; i < n; i++)
		table[cin.get() - 'A']++;
	
	std::sort(table, table + 26);
	
	long long sum = 0;
	int pos = 25;
	
	while (k > 0)
	{
		if (table[pos] < k)
		{
			k -= table[pos];
			sum += (sqr(table[pos] * 1LL));
			pos--;
		}
		else
		{
			sum += ( sqr(k * 1LL) );
			break;
		}
	}
	
	cout << sum << endl;
	
	return 0;
}