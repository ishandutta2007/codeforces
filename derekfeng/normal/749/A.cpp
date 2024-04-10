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
	int n;
	cin>>n;
	if (n%2==0){
		cout<<n/2<<"\n";
		for (int i=0;i<n/2;i++)
			cout<<"2 ";
	}
	if (n%2==1){
		cout<<(n-1)/2<<"\n"; 
		for (int i=0;i<(n-3)/2;i++)
			cout<<"2 ";
		cout<<"3";
	}
}