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
int tim[103];
int main() {
	int n;
	cin>>n;
	string s;
	getline (cin,s);
	for (int i=0; i<n; i++) {
		getline(cin,s);
		int num=0;
		int j=0;
		while (!isdigit(s[j])) j++;
		while (isdigit(s[j])) {
			num=num*10+s[j]-'0';
			j++;
		}
		if (s[7]=='p') num+=12;
 		num*=60;
		int num2=0;
		j++;
		while (isdigit(s[j])){
			num2=num2*10+s[j]-'0';
			j++;
		}
		int tm=num+num2;
		if (num==720||num==1440) tm-=720;
		tim[i]=tm;
	}
	int ans=1,caozuo=1;
	for (int i=1;i<n;i++){
		if (tim[i]<tim[i-1]){ans++;caozuo=1;continue;}
		if (tim[i]>tim[i-1]){caozuo=1;continue;}
		caozuo++;
		if (caozuo>10){ans++;caozuo=1;}
	}
	cout<<ans;
	return 0;
}