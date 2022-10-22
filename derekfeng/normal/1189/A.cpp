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
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
int n;
string s; 
int main(){
	cin>>n;cin>>s;
	if(n==1){
		cout<<1<<"\n"<<s;
		return 0;
	}
	int cnt=0;
	for (int i=0;i<s.size();i++){
		if (s[i]=='1') cnt++;
		else cnt--;
	}
	if (cnt==0) cout<<"2\n"<<s.substr(0,s.size()-1)<<" "<<s[s.size()-1];
	else cout<<"1\n"<<s;
}