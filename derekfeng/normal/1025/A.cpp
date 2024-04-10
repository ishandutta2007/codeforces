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
bool vis[200];
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	if (n==1){
		cout<<"Yes";
		return 0;
	}
	for (int i=0;i<s.size();i++){
		if (vis[s[i]]){
			cout<<"Yes";
			return 0;
		}
		vis[s[i]]=1;
	}
	cout<<"No";
	return 0;
}