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
map <string,int> mp;
int monthday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
bool okay(string s){
	if (isdigit(s[0]) && isdigit(s[1]) && s[2]=='-' && isdigit(s[3])
		 && isdigit(s[4]) && s[5]=='-' && isdigit(s[6]) && isdigit(s[7])
		 && isdigit(s[8]) && isdigit(s[9]));
	else return false;
	int days=0,months=0,years=0;
	for (int i=0;i<2;i++) days=days*10+s[i]-'0'; 
	for (int i=3;i<5;i++) months=months*10+s[i]-'0';
	for (int i=6;i<10;i++) years=years*10+s[i]-'0';
	if (years<2013 || years>2015) return false;
	if (months<1 || months>12) return false;
	if (days<1 || days>monthday[months]) return false;
	return true;
}
int main(){
	cin>>s;
	for (int i=0;i<s.size()-9;i++){
		string sub=s.substr(i,10);
		if (!okay(sub)) continue;
		mp[sub]++;
	}
	string ans;
	int res=0;
	for (map <string,int>::iterator it=mp.begin();it!=mp.end();it++){
		if (res<it->second){
			res=it->second;
			ans=it->first;
		}
	}
	cout<<ans;
	return 0;
}