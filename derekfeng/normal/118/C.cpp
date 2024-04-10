//Welcome To Haobanana!!!
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
#define mpk make_pair
using namespace std;
typedef pair<int,int> ii;
typedef vector <ii> vii;
int n,m;
string s;
vii v;
int main(){
	cin>>n>>m>>s;
	int res=1e9;
	string ans="";
	for (int i='0';i<='9';i++){
		v.clear();
		for (int j=0;j<n;j++)
			if (s[j]>i)
				v.push_back(mpk(s[j]-i,j));
			else
				v.push_back(mpk(i-s[j],2*n-j));
		sort (v.begin(),v.end());
		int cur=0;
		string w=s;
		for (int j=0;j<m;j++){
			cur+=v[j].first;
			if (v[j].second<n) w[v[j].second]=i;
			else w[2*n-v[j].second]=i;
		}
		if (cur<res || cur==res && ans>w){
			res=cur;
			ans=w;
		}
	}
	cout<<res<<endl<<ans;
	return 0;
}