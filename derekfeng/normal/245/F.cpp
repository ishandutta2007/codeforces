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
long long times[5000005];
string p[5000005];
int months_day[13]={0,31,60,91,121,152,182,213,244,274,305,335,366};
int main(){ 
	string s;
	long long n;
	int m;
	cin>>n>>m;
	int cnt=0;
	getline (cin,s); 
	while (getline(cin,s)){
		if (s=="0") break;
		p[cnt]=s;
		long long months=(s[5]-'0')*10+s[6]-'0';
		long long days=months_day[months-1]+(s[8]-'0')*10+s[9]-'0';
		long long hours=(days-1)*24+(s[11]-'0')*10+s[12]-'0';
		long long minutes=hours*60+(s[14]-'0')*10+s[15]-'0';
		long long seconds=minutes*60+(s[17]-'0')*10+s[18]-'0';
		times[cnt++]=seconds;
	}
	for (int i=m-1;i<cnt;i++){
		if (times[i]-times[i-m+1]<n){
			cout<<p[i].substr(0,19);
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}