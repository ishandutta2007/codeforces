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
map <int,int> mp;
int num1=0,num2=0,max1=-1,max2=-1,kil=0;
int n,m,k;
int main(void){
	cin>>n>>m>>k;
	vector <int> kol;
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		mp[-x]++;
		kol.push_back(-x); 
	}
	for (int i=0;i<m;i++){
		int x;
		cin>>x;
		mp[-x]--; 
		kol.push_back(-x); 
	}
	sort (kol.begin(),kol.end());
	for (int i=0;i<kol.size();i++) if (i==0 || kol[i]!=kol[i-1]){
		num1+=mp[kol[i]];
		if (num1>0)
			return puts("YES");
	}
	return puts("NO");
}