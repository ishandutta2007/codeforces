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
int t[200004]; 
string s;
int n,ans=0;
int main(){
	cin>>n>>s;
	int c=0;
	fill (t,t+200004,-2);
	t[100000]=-1;
	for (int i=0;i<n;i++){
		if (s[i]=='0') c--;
		else c++;
		if (t[c+100000]==-2) t[c+100000]=i;
		else ans=max(ans,i-t[c+100000]);
	}
	if (ans==1) ans=0;
	cout<<ans;
	return 0;
}