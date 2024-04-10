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
int n,a[200004];
bool ok[2][200004];
int main(){
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	ok[0][0]=1;
	for (int i=1;i<n;i++)ok[0][i]=ok[0][i-1]&(a[i]>a[i-1]);
	ok[1][n-1]=1;
	for (int i=n-2;i>=0;i--)ok[1][i]=ok[1][i+1]&(a[i]>a[i+1]);
	for (int i=0;i<n;i++){
		if (ok[0][i]&&ok[1][i]){
			cout<<"YES";return 0;
		} 
	}
	cout<<"NO";
}