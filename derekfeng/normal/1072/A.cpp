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
	int n,m,w;
	cin>>n>>m>>w;
	int ans=0;
	for (int i=n,j=m,p=0;p<w;i-=4,j-=4,p++){
		if (i==1 && j==1){ans++;continue;}
		ans+=(i+j)*2-4;
	}
	cout<<ans;
	return 0;
}