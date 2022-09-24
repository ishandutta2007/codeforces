#include<iostream>
#include<set>
#include<algorithm>
#include<math.h>
#include<string>
#include<utility>
using namespace std;
int main()
{
	int n;
	int r;
	cin >> n >> r;
	for (int i = 1; i < 10; i++)
	{
		if ((n * i) % 10 == r || (n*i) % 10 == 0)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}