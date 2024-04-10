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
typedef long long ll;
ll n,k;
string s;
ll ans[200004][30];
int main(){
	for (ll i=0;i<200004;i++)
		for (ll j=0;j<30;j++)
			ans[i][j]=1e9;
	cin>>n>>k;
	cin>>s;
	for (ll j=0;j<30;j++){
		ll l=-1;
		for (ll i=0;i<200004;i++){
			if (i<s.size() && s[i]==j+'a') l=i;
			if (l==-1) continue;
			ans[i][j]=min(ans[i][j],i-l);
		}
	}
	for (ll j=0;j<30;j++){
		ll l=-1;
		for (ll i=s.size()-1;i>=0;i--){
			if (s[i]==j+'a') l=i;
			if (l==-1) continue;
			ans[i][j]=min(ans[i][j],l-i);
		}
	}
	while (n--){
		string t;
		cin>>t;
		ll F=0;
		for (ll i=0;i<t.size();i++){
			if (ans[i][t[i]-'a']==1e9) F+=int(t.size());
			else F+=ans[i][t[i]-'a'];
		}
		cout<<F<<endl;
	}
	return 0;
}