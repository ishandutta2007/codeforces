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
int a[4],ans=0;
int main(){
	for (int i=0;i<4;i++) cin>>a[i];
	string s;
	cin>>s;
	for (int i=0;i<s.size();i++) ans+=a[s[i]-'0'-1];
	cout<<ans;
	return 0;
}