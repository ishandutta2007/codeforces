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
string s;
int main(){
	cin>>s;
	int ans=0,b=1;
	while (b<s.size()){
		if (s[b]==s[b-1]){ans++,s.erase(b-1,2),b-=2;}
		b++;
	}
	if (ans%2==0) cout<<"NO";
	else cout<<"YES";
}