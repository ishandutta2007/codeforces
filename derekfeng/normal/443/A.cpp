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
	getline (cin,s);
	set <char> emoji;
	for (int i=0;i<s.size();i++){
		if (islower(s[i])){
			emoji.insert(s[i]);
			i++;
		}
	}
	cout<<emoji.size();
	return 0;
}