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
	int x=0;
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		char op1,op2,op3;
		cin >> op1 >> op2 >> op3;
		if (op1=='+' || op2=='+' || op3=='+')
			x++;
		else
			x--;
	}
	cout << x << endl;
	return 0;
}