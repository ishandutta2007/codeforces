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
int t,n,a[100004];
int main(){
	cin>>t;
	while (t--){
		cin>>n;
		int l=-1,r=-1;
		for (int i=0;i<n;i++){
			cin>>a[i];
			if (a[i]>=r){
				l=r,r=a[i];
			}else if (a[i]>l){
				l=a[i];
			}
		}
		cout<<min(n-2,min(l,r)-1)<<"\n";
	}
}