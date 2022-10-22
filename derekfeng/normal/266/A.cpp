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
	int n,ans=0;
	string s;
	cin>>n>>s;
	for (int i=0;i<s.size();i++){
		int j;
		for (j=i+1;j<s.size() && s[j]==s[j-1];j++);
		j--;
		ans+=j-i;
		i=j;
	}
	cout<<ans;
	return 0;
}