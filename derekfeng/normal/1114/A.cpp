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
int x,z,y;
int a,b,c;
void no(){
	puts("NO");
	exit(0); 
}
int main(){
	cin>>x>>y>>z>>a>>b>>c;
	if (x>a) no();
	a-=x;
	if (a+b<y) no();
	int num=a+b-y;
	if (num+c<z) no();
	cout<<"YES";
}