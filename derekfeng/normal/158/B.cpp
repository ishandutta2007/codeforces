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
int rb[5];
int main(){
	for (int i=0;i<5;i++) rb[i]=0;
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int p;
		cin>>p;
		rb[p]++;
	} 
	cout<<rb[3]+rb[4]+(rb[2]*2+max(rb[1]-rb[3],0)+3)/4;
	return 0;
}