#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
using namespace std;
int n,ans=0;
char c[503][503];
int main(){
	cin>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin>>c[i][j];
	for (int i=1;i<n-1;i++)
		for (int j=0;j<n-1;j++)
			if (c[i][j]==c[i-1][j-1] && c[i][j]==c[i-1][j+1] && c[i][j]==c[i+1][j+1] && c[i][j]==c[i+1][j-1] && c[i][j]=='X')
				ans++;
	cout<<ans;
}