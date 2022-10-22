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
string s;
int main(){
	cin>>s;
	s+=s;
	int n=s.size();
	int ans=0,l;
	for (int i=0;i<n;i++){
		if (i==0 || s[i]==s[i-1]) l=i;
		ans=max(i-l+1,ans);
	}
	cout<<min(ans,n/2);
	return 0;
}