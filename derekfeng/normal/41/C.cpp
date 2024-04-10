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
	string s,t;
	cin>>s;
	for (int i=0;i<s.size();i++){
		if ((i==0 || i>= s.size()-3)  ||  s[i]!='d') t+=s[i];
		else{
			if (s.substr(i,3)=="dot") t+='.',i+=2;
			else t+=s[i];
		}
	}
	for (int i=1;i<t.size()-2;i++){
		if (t.substr(i,2)=="at"){
			cout<<t.substr(0,i)<<"@"<<t.substr(i+2);
			return 0;  
		}
 	}
}