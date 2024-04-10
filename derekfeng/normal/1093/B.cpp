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
	int n;
	cin>>n; 
	while (n--){
		string s;
		cin>>s;
		bool okay=1;
		sort (s.begin(),s.end());
		for (int i=1;i<s.size();i++)
			if (s[i]!=s[i-1]) okay=0;
		if (okay) cout<<"-1\n";
		else cout<<s<<endl;
	}
	return 0;
}