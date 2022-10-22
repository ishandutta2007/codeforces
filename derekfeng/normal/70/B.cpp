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
	int n,ans=0;
	string s;
	cin>>n;
	getline (cin,s);
	getline (cin,s);
	s+=' ';
	vector <int> v;
	for (int i=0;i<s.size();i++){
		int k=0;
		for (int j=i;s[j-1]!='.' && s[j-1]!='!' && s[j-1]!='?';j++){
			i=j;
			k++;
		}
		i++;
		if (k>n){
			cout<<"Impossible";
			return 0;
		}
		v.push_back(k); 
	}
	int s1=0;
	int num=0;
	while (1){
  		ans++;
    	int cnt=0;
   		int j;
    	for (j=s1;j<v.size();j++){
     		cnt+=v[j]+1;
      		if (cnt-1>n) break;
		}
		j--;
		if (j==v.size()-1) break;
		s1=j+1;
  	}
	cout<<ans;
	return 0;
}