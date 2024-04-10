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
	long long n,k;
	cin>>n>>k;
	if (k==1 || n==1 || k==2){
		cout<<"0";
		return 0;
	}
	if (k%2==1){
		if (n>(k-1)/2){
			cout<<min((k-1)/2,(n-(k-1)/2));
		}
		else cout<<0;
	}
	else{
		if (n>k/2)
			cout<<min((k-2)/2,(n-(k/2)));
		else cout<<0;
	}
	return 0;
}