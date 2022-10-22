#include <bits/stdc++.h>

#define int long long

using namespace std;

int query(int a, int b)
{
	cout << "?" << " " << a << " " << b << '\n';
	cout.flush();
	int qu;
	cin >> qu;
	return qu;
}

void answer(vector<int> vect)
{
	cout << "!" << " ";
	for(auto x : vect)
	{
		cout << x << " ";
	}
	cout << '\n';
	cout.flush();
}

int32_t main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int N;
    cin >> N;

    int q1 = query(1,2);
    int q2 = query(2,3);
    int q3 = query(1,3);

    int x3 = q3-q1;
    int x2 = q2-x3;
    int x1 = q3-q2;

    vector<int> res;
    res.push_back(x1);
    res.push_back(x2);
    res.push_back(x3);

    for(int i = 4 ; i <= N ; i++)
    {
    	int qu = query(i-1,i);
    	res.push_back(qu-res.back());
    }

    answer(res);

    return 0;
}