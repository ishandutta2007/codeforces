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
bool vis[29];
int main(){
	int n,k,ans=0;
	string s;
	cin>>n>>k>>s;
	for (int i=0;i<s.size();i++)
		vis[s[i]-96]=1;
	for (int i=1;i<=26 && k;i++){
		if (vis[i]){ans+=i;k--;vis[i+1]=0;}
	}
	if (k){cout<<"-1";return 0;}
	cout<<ans;
	return 0;
}