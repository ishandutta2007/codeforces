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
map <char,int> mp;
int main(){
	int n,k;
	string s;
	cin>>n>>k>>s;
	int m=k/2;
	mp['(']=0;
	mp[')']=0;
	string ans="";
	for (int i=0;i<s.size();i++)
		if (mp[s[i]]<m) ans+=s[i],mp[s[i]]++;
	cout<<ans;
	return 0;
}