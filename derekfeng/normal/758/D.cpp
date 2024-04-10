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
typedef long long ll;
string n,k; 
bool okay(string s){
	if (s.size()<n.size()) return true;
	if (s.size()>n.size()) return false;
	for (int i=0;i<s.size();i++){
		if (n[i]<s[i]) return false; 
		if (n[i]>s[i]) return true;
	}
	return false;
}
bool okay1(string s){
	if (s.size()==1 || s[0]!='0') return true;
	else return false;
}
ll go_int(string s){
	ll res=0;
	for (int i=0;i<s.size();i++)
		res=res*10+s[i]-'0';
	return res;
}
vector <string> v;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for (int i=k.size()-1;i>=0;){
		int j=i;
		int qq=-1;
		while (j>=0 && okay(k.substr(j,i-j+1))){
			if (okay1(k.substr(j,i-j+1))) qq=j;
			j--;
		}
		v.push_back(k.substr(qq,i-qq+1)); 
		i=qq-1;
	}
	ll base=go_int(n),ans=0;
	reverse (v.begin(),v.end());
	for (int i=0;i<v.size();i++)
		ans=ans*base+go_int(v[i]);
	cout<<ans;
}