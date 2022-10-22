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
int n;
string s;
vector <int> res;
int main(){
	cin>>n>>s;
	for (int i=0;i<s.size();){
		if (s[i]=='W'){
			i++;
			continue;
		}
		int j;
		for (j=i;j<s.size() && s[j]=='B';j++);
		res.push_back(j-i); 
		i=j;
	}
	cout<<res.size()<<endl;
	for (int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
}