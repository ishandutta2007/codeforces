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
	int d1,d2,d3,ans=0;
	cin>>d1>>d2>>d3;
	ans=d1+d2+d3;
	ans=min(ans,d1+d1+d2+d2);
	ans=min(ans,d1+d3+d3+d1);
	ans=min(ans,d2+d2+d3+d3);
	cout<<ans;
	return 0;
}