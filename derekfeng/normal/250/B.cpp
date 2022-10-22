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
	int ntest;
	cin>>ntest;
	while (ntest--){
		vector <string> pl;
		string s,ans="";
		cin>>s;
		int beginning=0;
		if (s[0]==':' && s[1]==':')
			beginning=1;
		for (int i=beginning;i<s.size();){
			if (s[i]==':' && s[i-1]==':'){
				i++;
				pl.push_back("huaji");
				continue;
			}
			string x="";
			int j;
			for (j=i;j<s.size() && s[j]!=':';j++) x+=s[j]; 
			pl.push_back(x);
			i=j+1;
		}
		for (int i=0;i<pl.size();i++){
			if (i!=0) ans+=":";
			if (pl[i]=="huaji"){
				for (int j=pl.size();j<=8;j++){
					if (j!=pl.size()) ans+=":";
					ans+="0000";
				}
				continue;
			}
			int x=pl[i].size();
			for (int j=0;j<4-x;j++) ans+="0";
			ans+=pl[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}