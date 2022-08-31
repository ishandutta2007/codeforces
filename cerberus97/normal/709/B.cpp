#include <iostream>
#include <algorithm>

using namespace std;

int x[(int)1e5];

int getAns(int n, int bef, int aft, int a, bool isPoint)
{
	int visited = 0;

	if (isPoint)
		++visited;

	if (visited >= n-1)
		return 0;

	int temp = 1e9, ans = 1e9;

	if (aft != n)
	{
		temp = x[aft]-a;
		++visited;	

		for (int i = aft; i < n; ++i, ++visited)
		{
			if (visited == n-1)
			{
				ans = min(ans, temp);
				break;
			}

			else if (2+bef+visited-n >= 0)
			{
				ans = min(ans, 2*temp + a - x[2+bef+visited-n]);
			}

			temp += x[min(i+1,n-1)]-x[i];
		}
	}

	if (bef != -1)
	{
		temp = a - x[bef];
		visited = 1;

		if (isPoint)
			++visited;

		for (int i = bef; i >= 0; --i, ++visited)
		{
			if (visited == n-1)
			{
				ans = min(ans, temp);
				break;
			}

			else if (n+aft-2-visited < n)
			{
				ans = min(ans, 2*temp + x[n+aft-2-visited]-a);
			}

			temp += x[i]-x[max(i-1, 0)];
		}
	}

	return ans;

	/*
	int ans = 1e9, left = pos, right = n-pos-1;

	if (n == 1)
		return pos(a-x[0]);

	if (n == 2)
	{

	}

	if (!left)
		return x[n-2]-x[0];

	if (!right)
		return x[n-1]-x[1];

	if (left == 1)
		return min(x[n-1]-x[1], min(2*(x[1]-x[0]) + x[n-2] - x[1], 2*(x[n-2]-x[1]) + x[1] - x[0]));

	if (right == 1)
		return min(x[n-2]-x[0], min(2*(x[n-1] - x[n-2]) + x[n-2] - x[1], 2*(x[n-2]-x[1]) + x[n-1] - x[n-2]));

	int a1 = x[pos]-x[1], a2 = x[1]-x[0], b1 = x[n-2]-x[pos], b2 = x[n-1]-x[n-2];
	return min(min(2*a1 + b1 + b2, 2*b1 + a1 + a2), min(2*(a1 + a2) + b1, 2*(b1 + b2) + a1));
	*/
}

int main()
{
	int n, a, bef = -1, aft = 0;
	cin >> n >> a;

	for (int i = 0; i < n; ++i)
		cin >> x[i];

	sort(x, x+n);
	bool isPoint = false;

	for (int i = 0; i < n; ++i)
	{
		if (x[i] < a)
		{
			++bef;
			++aft;
		}

		else if (x[i] == a)
		{
			++aft;
			isPoint = true;
			break;
		}
	}

	cout << getAns(n, bef, aft, a, isPoint);
}