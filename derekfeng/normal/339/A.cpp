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
	string s;
	cin>>s;
	vector <char> pp;
	for (int i=0;i<s.size();i+=2){
		pp.push_back(s[i]);  
	}
	sort (pp.begin(),pp.end());
	for (int i=0;i<pp.size();i++){
		cout<<pp[i];
		if (i!=pp.size()-1) cout<<"+";
	}
	return 0;
}