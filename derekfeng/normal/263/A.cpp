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
int main(){
	char c[6][6];
	for (int i=1;i<=5;i++)
		for (int j=1;j<=5;j++){
			cin>>c[i][j]; 
			if (c[i][j]=='1'){
				cout<<abs(i-3)+abs(j-3);
				return 0; 
			}
		}
}