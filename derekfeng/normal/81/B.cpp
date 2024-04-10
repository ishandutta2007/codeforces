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
string s,res;
string ans[303];
int main(){
	int ld=0; 
	getline(cin,s);
	if (s.size()==0){
		puts("");
		return 0;
	}
	for (int i=0;i<s.size();){
		if (s[i]==' '){
			i++;
			continue;
		}
		if (s[i]==','){
			ans[ld++]=",";
			i++;
			continue;
		}
		if (s[i]=='.'){
			ans[ld++]="...";
			i+=3;
			continue;
		}
		int j;
		for (j=i;j<s.size() && isdigit(s[j]);j++) ans[ld]+=s[j];
		ld++;
		i=j;
	}
	for (int i=0;i<ld;i++){
		if (ans[i]==","){
			res+=",";
			if (i!=ld-1)res+=" ";
			continue;
		}
		if (ans[i]=="..."){
			if (i!=0 && ans[i-1]!=",") res+=" ...";
			else res+="...";
			continue;
		}
		if (i!=0 && isdigit(ans[i-1][0])) res+=" "+ans[i];
		else res+=ans[i];
	}
	cout<<res;
	return 0;
}