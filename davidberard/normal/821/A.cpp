/* Codeforces 420
 *
 */
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
#include <set>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef vector<int> Vint;

int  N;

bool isIn(int row, int col, const vector<vector<int> >& vals)
{
	int val = vals[row][col];
	if(val == 1)
		return true;

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			if(i!=col && j!=row)
				if(vals[row][i]+vals[j][col] == val)
					return true;

	return false;
}

int main()
{
	cin >> N;
	vector<vector<int> > elements(N);
	for(int i=0;i<N;++i)
	{
		elements[i].resize(N);
		for(int j=0;j<N;++j)
			cin >> elements[i][j];
	}
	
	bool good = true;

	for(int row=0;row < N && good;++row)
	{
		for(int col=0;col < N && good;++col)
		{
			if(!isIn(row, col, elements))
				good = false;
		}
	}

	if(good == true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	
	
	

	return 0;
}