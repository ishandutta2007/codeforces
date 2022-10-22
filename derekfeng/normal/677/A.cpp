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
#define QYF sh**
#define NAH fu*****
using namespace std;
int n,h;
int main(){
	cin>>n>>h;
	int ans=n;
	while (n--){
		int x;
		cin>>x;
		if (x>h) ans++;
	}
	cout<<ans;
	return 0;
}