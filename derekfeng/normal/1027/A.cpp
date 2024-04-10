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
	int ncase;
	cin>>ncase;
	while (ncase--){
		string s;
		int n;
		cin>>n>>s;
		bool q=0;
		for (int i=0;i<s.size()/2;i++){
			if (s[i]==s[s.size()-1-i]) continue;
			if (abs(s[i]-s[s.size()-1-i])==2) continue;
			cout<<"NO"<<endl;
			q=1;
			break;
		}
		if (q) continue;
		else cout<<"YES"<<endl;
	}
	return 0;
}