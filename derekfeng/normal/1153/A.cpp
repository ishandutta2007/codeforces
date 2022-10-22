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
int n,t;
int ans=0,num=1e6;
int main(){
	cin>>n>>t;
	for (int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		int res;
		if (x>=t) res=x-t;
		else res=y-(t-x)%y;
		if (res==y && x<t) res=0; 
		if (res<num) ans=i,num=res;
	}
	cout<<ans;
}