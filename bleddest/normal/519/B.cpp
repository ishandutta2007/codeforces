#include<vector>
#include<iostream>
#include<set>
#include<random>
#include<ctime>
#include<cstdio>

using namespace std;

int main()
{              
	int n;
	scanf("%d", &n);  // cin >> n
	multiset<int> a;
	for(int i = 0; i < n; i++)
	{
	 	int x;
	 	scanf("%d", &x); // cin >> x
	 	a.insert(x);
	}
	multiset<int> b;
	for(int i = 0; i < n - 1; i++)
	{
	 	int x;
	 	scanf("%d", &x); // cin >> x
	 	b.insert(x);
	}
	multiset<int> c;
	for(int i = 0; i < n - 2; i++)
	{
	 	int x;
	 	scanf("%d", &x); // cin >> x
	 	c.insert(x);
	}

	int ans1 = 0, ans2 = 0;


	for(auto x : b)
		if(c.find(x) == c.end())
			ans2 = x;
		else
			c.erase(c.find(x));
	for(auto x : a)
		if(b.find(x) == b.end())
			ans1 = x;
		else
			b.erase(b.find(x));

	cout << ans1 << endl << ans2 << endl;
}