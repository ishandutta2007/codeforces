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
int n,a[100004];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	int q;cin>>q;
	while (q--){
		int l,r;cin>>l>>r;
		cout<<(a[r]-a[l-1])/10<<"\n";
	}
}