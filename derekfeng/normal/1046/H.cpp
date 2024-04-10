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
string s[100004];
int v[100004];
map <int,long long> mp;
int main(){
	fill (v,v+100004,0);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s[i];
		vector <int> g[26];
		for (int j=0;j<s[i].size();j++)
			g[s[i][j]-'a'].push_back(1);
		for (int j=0;j<26;j++)
			if (g[j].size()%2==1) v[i]|=(1<<j);
		mp[v[i]]++;
	}
	long long ans=0;
	for (int i=0;i<n;i++){
		int num=ans;
		ans+=mp[v[i]]-1;
		for (int j=0;j<26;j++){
			if ((v[i]&(1<<j))>0){
				ans+=mp[v[i]^(1<<j)];
			}
			else{
				ans+=mp[v[i]|(1<<j)];
			}
		}
	}
	cout<<ans/2;
	return 0;
}