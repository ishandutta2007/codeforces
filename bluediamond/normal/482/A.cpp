// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	int st = 1, dr = n;
	int last;
	for (int i = 1; i <= k; i++)
	{
		if (i % 2 == 1)
		{
			cout << st << " ";
			last = st;
			st++;
		}
		else
		{
			cout << dr << " ";
			last = dr;
			dr--;
		}
	}
	if (st - 1 == last)
		for (int j = st; j <= dr; j++)
			cout << j << " ";
	else
		for (int j = dr; j >= st; j--)
			cout << j << " ";
	cout << "\n";

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file