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

const double eps = 1e-8;
const double PI = acos(-1.0);
const int N = 2*111111;
vector<long long> a,t;
int n;

int main()
{
	ios_base::sync_with_stdio(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	a.resize(N);
	t.resize(N);
	int m;
	long long sum=0;
	n=1;
	cout << fixed << setprecision(6);
	cin >> m;
	for (;m;m--)
	{
		int tp;
		cin >> tp;
		if (tp==1)
		{
			int id,x;
			cin >> id >> x;
			t[id]+=x;
			sum += 1LL*x*id;
		}else
		if (tp==2)
		{
			n++;
			cin >> a[n];
			t[n]=0;
			sum += a[n];
		}
		else
		{
			t[n-1]+=t[n];
			sum -= t[n]+a[n];
			n--;
		}
		cout << 1.0*sum/n << endl;
	}
	return 0;
}