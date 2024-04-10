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
int n,a[103],ans=0;
int main(){
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++){
		int j;
		for (j=i+1;j<n && a[j]==a[j-1]+1;j++);
		j--;
		int p=j-i-1;
		if (i!=j && a[j]==1000) p++;
		else if (i!=j && a[i]==1) p++; 
		ans=max(ans,p);
	}
	cout<<ans;
	return 0;
}