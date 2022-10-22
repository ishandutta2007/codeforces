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
	string s;
	cin>>s;
	int n=s.size();
	int l,r;
	for (int i=0;i<n;i++)
		if (s[i]!='0' && s[i]!='.'){
			l=i;
			break;
		}
	for (int i=n-1;i>=0;i--)
		if (s[i]!='0' && s[i]!='.'){
			r=i;
			break;
		}
	string ans="";
	ans+=s[l];
	if (r!=l) ans+='.';
	for (int i=l+1;i<=r;i++)
		if (s[i]!='.')
			ans+=s[i];
	int p=n;
	for (int i=0;i<n;i++)
		if (s[i]=='.'){
			p=i;
			break;
		}
	int pl=p-l;
	if (pl==1){
		cout<<ans;
		return 0;
	}
	if (pl>0) pl--;
	ans+="E";
	cout<<ans<<pl;
	return 0;
}