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
string s[1003];
int main(){
	int n;
	cin>>n;
	bool q=0;
	for (int i=0;i<n;i++){
		cin>>s[i];
		if (s[i][0]=='O' && s[i][1]=='O' && !q){
			s[i][0]='+';
			s[i][1]='+';
			q=1;
		}
		if (s[i][3]=='O' && s[i][4]=='O' && !q){
			s[i][3]='+';
			s[i][4]='+';
			q=1;
		}
	}
	if (!q) cout<<"NO";
	else{
		cout<<"YES"<<endl;
		for (int i=0;i<n;i++) cout<<s[i]<<endl;
	}
	return 0;
}