#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool contains_8(int n)
{
	if (n < 0)
		n = -n;
	
	while (n != 0)
	{
		if (n % 10 == 8)
			return true;
		n /= 10;
	}
	return false;
}

int main()
{
	int num;
	cin >> num;
	
	int dn = 0;
	
	num++;
	dn++;
	
	while (true)
	{
		if (contains_8(num))
		{
			cout << dn << endl;
			break;
		}
		dn++;
		num++;
	}
	
	return 0;
}