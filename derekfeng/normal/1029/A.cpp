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
int n,k;
string s;
int main(){
	cin>>n>>k>>s;
	string p=s;
	string s1;
	for (int i=1;i<=n;i++){
		string p=s+s.substr(n-i,i);
		if (p.substr(p.size()-n,n)==s){
			s1=s.substr(n-i,i);
			break; 
		}
	}
	string ans="";
	ans+=s;
	for (int i=1;i<k;i++)
		ans+=s1;
	cout<<ans;
	return 0;
}