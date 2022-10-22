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
int main(){
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	string now[2];
	bool q=0;
	for (int i=0;i<s.size();i++)
		if (s[i]=='*') q=1;
	if (!q){
		if (s!=t) cout<<"NO";
		else cout<<"YES";
		return 0;
	}
	now[0]="",now[1]="";
	int p=0;
	for (int i=0;i<s.size();i++){
		if (s[i]!='*') now[p]+=s[i];
		else p++;
	}
	string l=now[0],r=now[1];
	if (l.size()+r.size()>t.size()){
		puts("NO");
		return 0;
	}
	if (t.substr(0,l.size())==l && t.substr(t.size()-r.size(),r.size())==r)
		puts("YES");
	else puts("NO");
	return 0;
}