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
string names[1003];
int scor[1003];
vector <string> ans;
map <string,int> mp;
map <string,int> mp2;
map <string,bool> mp3;
int main(){
	int n,m=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>names[i]>>scor[i];
	}
	for (int i=0;i<n;i++){
		mp[names[i]]+=scor[i];
	}
	for (int i=0;i<n;i++)
		m=max(m,mp[names[i]]);
	for (int i=0;i<n;i++){
		if (mp[names[i]]==m){
			ans.push_back(names[i]);
			mp3[names[i]]=1;
		}
	}
	if (ans.size()==1){
		cout<<ans[0];
		return 0;
	}
	for (int i=0;i<n;i++){
		mp2[names[i]]+=scor[i];
		if (mp2[names[i]]>=m && mp3[names[i]]){
			cout<<names[i];
			return 0;
		}
	}
}