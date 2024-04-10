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
int main(){
	int n,res=0;
	cin>>n;
	while (n--){
		int num=0;
		int a,b,c;
		cin>>a>>b>>c;
		if (a==1) num++;
		if (b==1) num++;
		if (c==1) num++;
		if (num>1) res++;
	}
	cout<<res;
	return 0;
}