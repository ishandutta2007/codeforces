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
string s;

int main()
{
	ios_base::sync_with_stdio(0);

	//ifstream cin("input.txt");
//	ofstream cout("output.txt");
	
	cin >> n;
	cin.ignore();
	getline(cin, s);
	
	int sR=-1,fR,
		sL=-1,fL;
	for (int i=0; i<s.length(); i++)
		if (s[i]=='R')
		{
			fR = i+1;
			if (sR==-1)
				sR = i+1;
		}else
		if (s[i]=='L')
		{
			fL = i+1;
			if (sL==-1)
				sL = i+1;
		}
	if (sR==-1)
		cout << fL << " " << sL-1 << endl;
	else
	if (sL==-1)
		cout << sR << " " << fR+1 << endl;
	else
		cout << sR << " " << fR << endl;
	return 0;
}