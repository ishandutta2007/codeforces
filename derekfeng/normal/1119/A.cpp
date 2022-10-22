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
int n;
int c[300004];
int p[300004];
int main(){
	cin>>n;
	int q=n;
	for (int i=0;i<n;i++){
		cin>>c[i];
		if (i!=0 && c[i]==c[i-1]) i--,n--,p[i]++;
		else p[i]=1;
	}
	if (c[0]!=c[n-1])cout<<q-1;
	else cout<<max(q-p[0]-1,q-p[n-1]-1); 
}