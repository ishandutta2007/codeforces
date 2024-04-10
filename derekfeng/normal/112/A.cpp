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
	string s1,s2;
	cin>>s1>>s2;
	for (int i=0;i<s1.size();i++){
		if ('A'<=s1[i] && 'Z'>=s1[i]) s1[i]+='a'-'A';
		if ('A'<=s2[i] && 'Z'>=s2[i]) s2[i]+='a'-'A';
	}
	if (s1<s2){
		puts("-1");
		return 0;
	}
	if (s1==s2){
		puts("0");
		return 0;
	}
	if (s1>s2){
		puts("1");
		return 0;
	}
}