// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

const int N = (int) 1e5 + 7;
int cur[N];
int n, q;
int l[N], r[N], mask[N];
int sol[N],cnt0[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= q; i++)
		cin >> l[i] >> r[i] >> mask[i];
	for (int bit = 0; bit <= 30; bit++)
	{
		for (int i = 1; i <= q; i++)
			if (mask[i] & (1 << bit))
			{
				cur[l[i]]++;
				cur[r[i] + 1]--;
			}
		int now = 0;
		for (int i = 1; i <= n; i++)
		{
			now += cur[i];
			int pun = (now >= 1);
			sol[i] += pun * (1 << bit);
			cnt0[i] = cnt0[i - 1] + (pun == 0);
			cur[i] = 0;
		}
		for(int i=1;i<=q;i++)
			if (!(mask[i] & (1 << bit)))
			{
				int cate = cnt0[r[i]] - cnt0[l[i] - 1];
				if (!cate)
				{
					cout << "NO\n";
					return 0;
				}
			}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++)
		cout << sol[i] << " ";
	cout << "\n";
}


/**

 ***
 ****
  ***


**/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file