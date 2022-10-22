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
bool okay(int x){
	int op=x;
	while (op>0){
		int m=op%10;
		op/=10;
		if (m!=4 && m!=7) return false;
	}
	return true;
}
int main(){
	int kil=0;
	string s;
	cin>>s;
	for (int i=0;i<s.size();i++){
		char c;
		c=s[i];
		if (c=='4' || c=='7') kil++;
	}
	if (kil!=0 && okay(kil)) cout<<"YES";
	else cout<<"NO";
	return 0;
}