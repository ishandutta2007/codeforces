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
int n;
string s;
int k[28];
int main(){
	cin>>n>>s;
	for (int i=0;i<n;i++){
		k[s[i]-'a']++;
	}
	string ans;
	for (int i=0;i<26;i++){
		while (k[i]--)
			ans+=i+'a';
	}
	cout<<ans;
	return 0;
}