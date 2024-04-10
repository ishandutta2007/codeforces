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
int d[3][10];
void dfs(int x){
}
int main(){
	string a,b,c;
	cin>>a>>b>>c;
	reverse (a.begin(),a.end());
	reverse (b.begin(),b.end());
	reverse (c.begin(),c.end());
	if (a>b) swap(a,b);
	if (a>c) swap(a,c);
	if (b>c) swap(b,c);
	if (a[0]==b[0] && b[0]==c[0]){
		if (a[1]==b[1] && b[1]==c[1]){
			cout<<"0";return 0;
		}
		if (a[1]==b[1]-1 && b[1]==c[1]-1){
			cout<<"0";return 0;
		}
	}
	if (a[0]==b[0] && (a[1]==b[1] || a[1]==b[1]-1 || a[1]==b[1]-2)){
		cout<<"1";return 0;
	}
	if (a[0]==c[0] && (a[1]==c[1] || a[1]==c[1]-1 || a[1]==c[1]-2)){
		cout<<"1";return 0;
	}
	if (c[0]==b[0] && (c[1]==b[1] || b[1]==c[1]-1 || b[1]==c[1]-2)){
		cout<<"1";return 0;
	}
	cout<<"2";return 0;
}