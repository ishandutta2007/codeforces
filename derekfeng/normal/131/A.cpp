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
bool sh_c(string s){
	for (int i=1;i<s.size();i++)
		if (!(s[i]>='A' && s[i]<='Z'))
			return false;
	return true;
}
int main(){
	string s;
	cin>>s;
	if (!sh_c(s)) cout<<s;
	else{
		if (s[0]>'Z') cout<<char(s[0]+'A'-'a');
		else cout<<char(s[0]+'a'-'A');
		for (int i=1;i<s.size();i++)
			cout<<char(s[i]+'a'-'A');
	}
}