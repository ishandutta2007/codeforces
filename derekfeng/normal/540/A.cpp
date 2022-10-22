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
string s1,s2;
int main(){
	int n,ans=0;
	cin>>n>>s1>>s2;
	for (int i=0;i<n;i++){
		if (s2[i]<s1[i]) swap(s2[i],s1[i]);
		ans+=min(s2[i]-s1[i],s1[i]+10-s2[i]);
	}
	cout<<ans;
	return 0;
}