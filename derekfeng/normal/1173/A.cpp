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
int x,y,z;
int main(){
	int x,y,z,a=0,b=0,c=0;
	cin>>x>>y>>z;
	for (int i=0;i<=z;i++){
		int t1=x+i,t2=y+z-i;
		if (t1>t2) a++;
		if (t1==t2) b++;
		if (t1<t2) c++;
	}
	if (a==0 && b==0 && c>0) cout<<"-";
	else if (a==0 && b>0 && c==0) cout<<"0";
	else if (a>0 && b==0 && c==0) cout<<"+";
	else cout<<"?";
}