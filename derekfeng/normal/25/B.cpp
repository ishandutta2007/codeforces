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
string s;
int main(){
	cin>>n>>s;
	vector<int>ans;
	for (;n>=3;n-=3) ans.push_back(3);
	if (n==2) ans.push_back(2);
	if (n==1) ans.pop_back(),ans.push_back(2),ans.push_back(2);
	int j=0;
	for (int i=0;i<ans.size();i++){
		while (ans[i]--) 
			cout<<s[j++];
		if (i!=ans.size()-1) cout<<"-";
	}    
	return 0;
}