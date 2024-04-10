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
	int k,r;
	cin>>k>>r;
	for (int i=1;i<=10;i++){
		if (k*i%10==0){
			cout<<i;
			return 0;
		}
		if (k*i>=r && (k*i-r)%10==0){
			cout<<i;
			return 0;
		}
	}
	return 0;
}