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
const int MOD=1e9+7;
int a,b,k;
string s,t;
int main(){
	cin>>s>>t>>k;
	a=s.size(),b=t.size();
	if (a!=b){
		cout<<"0";
		return 0;
	}
	long long x=0,y=0;
	for (int i=1;i<b;i++){
		char c=s[s.size()-1];
		s.erase(s.end()-1);
		s.insert(s.begin(),c);
		if (s==t) x++;
		else y++;
	}
	long long same_[100003],different_[100003];
	for (int i=0;i<100003;i++) same_[i]=0,different_[i]=0;
	same_[1]=x,different_[1]=y;
	char c=s[s.size()-1];
	s.erase(s.end()-1);
	s.insert(s.begin(),c);
	if (s==t) x++,same_[0]++;
	else y++;
	different_[0]=a-same_[0];
	for (int i=2;i<=k;i++){
		same_[i]=(same_[i-1]*(x-1)%MOD+different_[i-1]*x%MOD)%MOD;
		different_[i]=(same_[i-1]*y%MOD+different_[i-1]*(y-1)%MOD)%MOD;
	}
	cout<<same_[k];
	return 0;
}