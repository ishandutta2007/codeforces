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
vector <int> ans;
int n; 
string s;
int main(){
	cin>>n>>s;
	for (int i=0;i<n;i++){
		int x=s[i]-'0';
		if (x==2 || x==3 || x==5 || x==7) ans.push_back(x); 
		if (x==4){
			ans.push_back(3);
			ans.push_back(2); 
			ans.push_back(2);   
		}
		if (x==6){
			ans.push_back(5);
			ans.push_back(3);  
		}
		if (x==8){
			ans.push_back(7);
			ans.push_back(2);
			ans.push_back(2);
			ans.push_back(2);    
		}
		if (x==9){
			ans.push_back(7); 
			ans.push_back(3);
			ans.push_back(3);
			ans.push_back(2);   
		}
	}
	sort (ans.begin(),ans.end()); 
	for (int i=ans.size()-1;i>=0;i--) cout<<ans[i];
}