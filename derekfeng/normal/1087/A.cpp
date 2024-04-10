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
	string s,ans;
	cin>>s;
	for (int j=int(s.size())/2,i=(int(s.size())-1)/2;i>=0;i--,j++){
		if (int(s.size())%2==1){
			ans+=s[j];
			if (i!=j) ans+=s[i];
		}
		else{
			ans+=s[i];
			if (i!=j) ans+=s[j];
		}
	}
	cout<<ans;
	return 0;
}