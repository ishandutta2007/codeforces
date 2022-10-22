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
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
map <char,char> mp;
int main(){
	int n;
	string a;
	cin>>n>>a; 
	for (char c='1';c<='9';c++){
		char t;
		cin>>t;
		mp[c]=t;
	}
	int mm=0;
	while (mm<a.size() && a[mm]>=mp[a[mm]]) mm++;
	for (int i=mm;i<a.size();i++){
		if (a[i]<=mp[a[i]]) a[i]=mp[a[i]];
		else break;
	}
	cout<<a;
}