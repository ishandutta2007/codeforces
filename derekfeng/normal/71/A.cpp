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
	int n;
	cin>>n;
	while (n--){
		cin>>s;
		int p=s.size();
		if (p<=10){
			cout<<s<<endl;
			continue;
		}
		else cout<<s[0]<<s.size()-2<<s[s.size()-1]<<endl;
	}
	return 0;
}