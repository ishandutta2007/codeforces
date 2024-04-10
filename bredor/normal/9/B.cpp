//  228

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define LL long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
int n;
double x[110], fx, fy, vb, vs;

double dis(int i) 
{
	double dx = fx - x[i], dy = fy;
	return sqrt(dx * dx + dy * dy);
}

double get(int i) 
{
	double t1 = x[i] / vb;
	double t2 = dis(i) / vs;
	return t1 + t2;
}

int main()
{
	cin >> n >> vb >> vs;
	for(int i = 1; i <= n; i++)	cin >> x[i];
	cin >> fx >> fy;
	
	double T = 1e18, d;
	int res;
	
	for(int i = 2; i <= n; i++) 
	{
		double t = get(i);
		if(t < T)
			res = i, T = t, d = dis(i);
		else if(t == T && dis(i) < d)
			res = i, d = dis(i);
	}
	
	cout << res << endl;
	return 0;
}