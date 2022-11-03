#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const double eps = 1e-8;
const double PI = acos(-1.0);

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;
	cin >> n;
	int sum=0;
	for (int i=0; i<n; i++)
	{
		int a,b;
		cin >> a >> b;
		sum += a;
	}
	while (sum>500)
	{
		cout << 'G';
		sum -= 1000;
		n--;
	}
	while (n)
	{
		cout << 'A';
		n--;
	}
	cout << endl;
	return 0;
}