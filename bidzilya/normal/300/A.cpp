#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

int n;
vector<int> A,a,b,c;

int main()
{
	ios_base::sync_with_stdio(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	cin >> n;
	A.resize(n);
	for (int i=0; i<n; i++)
		cin >> A[i];
	sort(A.begin(), A.end());
	if (n > 3 && A[0]<0 && A[1]<0 && A[2]<0)
	{
		cout << 1 << " " << A[0] << endl;
		cout << 2 << " " << A[1] << " " << A[2] << endl;
		cout << n-3 << " ";
		for (int i=3; i<n; i++)
			cout << A[i] << " ";
		cout << endl;
	}else
	{
		cout << 1 << " " << A[0] << endl;
		cout << 1 << " " << A[n-1] << endl;
		cout << n-2 << " ";
		for (int i=1; i<n-1; i++)
			cout << A[i] << " ";
		cout << endl;
	}	
	return 0;
}