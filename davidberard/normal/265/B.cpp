#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	lli seconds = 0;
	int curr;
	int h = 0;
	for(int i=0;i<N;++i)
	{
		cin >> curr;
		if(curr > h)
		{
			seconds += (curr-h);
			h=curr;
		}
		else if(curr < h)
		{
			seconds += (h-curr);
			h=curr;
		}
		seconds += 1;
	}
	seconds += N-1;
	cout << seconds << endl;

	return 0;
}