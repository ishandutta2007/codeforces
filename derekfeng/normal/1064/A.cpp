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
int a,b,c;
int main(){
	cin>>a>>b>>c;
	int ans=1e9;
	for (int i=a;i<=200;i++)
		for (int j=b;j<=200;j++)
			for (int k=c;k<=200;k++){
				if (i+j>k && i+k>j && j+k>i) ans=min(ans,i-a+j-b+k-c);
			}
	cout<<ans;
	return 0;
}