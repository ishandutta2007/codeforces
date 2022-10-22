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
#include <bits/stdc++.h>
using namespace std;
int n; 
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			if (i%j==0 && i*j>n && i/j<n){
				cout<<i<<" "<<j;
				return 0;
			}
	puts("-1");
}