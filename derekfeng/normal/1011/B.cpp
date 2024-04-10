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
int a[104],fod[103],n,m;
bool check(int x){
	int num=0;
	for (int i=1;i<=100;i++)
		num+=fod[i]/x;
	if (num>=n) return true;
	else return false;
}
int main() {
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>a[i];
		fod[a[i]]++;
	}
	int i;
	for (i=1;;i++){
		if (!check(i)) break; 
	} 
	cout<<i-1; 
}