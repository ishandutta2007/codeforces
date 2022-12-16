#include <iostream>

using namespace std;
typedef long long int lli;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	int prices[100000];
	int minPrice = 1000000000;
	for(int i=0;i<n;++i)
	{
		cin >> prices[i];
		if(prices[i] < minPrice)
			minPrice = prices[i];
	}
	bool poss = true;
	lli amt = 0;
	for(int i=0;i<n;++i)
	{
		if((prices[i]-minPrice)%k != 0)
		{
			poss = false;
			break;
		}
		amt += (prices[i]-minPrice)/k;
	}
	if(poss == false)
		cout << -1 << endl;
	else
		cout << amt << endl;

	return 0;
}