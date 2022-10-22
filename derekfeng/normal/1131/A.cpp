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
int w1,h1,w2,h2; 
int ans=0;
int main(){
	cin>>w1>>h1>>w2>>h2;
	ans+=w2+2;
	ans+=2*(h2-1);
	ans+=w1+2-w2;
	ans+=2*h1;
	ans+=w1+2;
	cout<<ans;
}