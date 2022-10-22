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
	int big_=0,small_=0;
	for (int i=0;i<s.size();i++){
		if (islower(s[i])) small_++;
		else big_++; 
	}
	if (small_<big_){
		for (int i=0;i<s.size();i++)
			if (islower(s[i]))
				s[i]+='A'-'a';
	}
	else{
		for (int i=0;i<s.size();i++)
			if (!islower(s[i]))
				s[i]+='a'-'A';
	}
	cout<<s;
	return 0;
}