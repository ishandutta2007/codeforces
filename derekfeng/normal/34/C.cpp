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
int maxs=0;
bool vis[1004];
int main(){
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]==',') continue;
		int num=0;
		int j;
		for (j=i;j<s.size() && s[j]!=',';j++) num=num*10+s[j]-'0';
		j--;
		i=j;
		vis[num]=1;
		maxs=max(maxs,num);
	}
	int l=1;
	for (int i=1;i<=maxs;i++){
		if (!vis[i]) continue;
		int j;
		for (j=i;j<=maxs && vis[j];j++);
		j--;
		if (i==j) cout<<i;
		else cout<<i<<"-"<<j;
		if (j!=maxs) cout<<",";
		i=j;
	}
	return 0;
}