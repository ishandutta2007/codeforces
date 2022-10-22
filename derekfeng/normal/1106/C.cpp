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
using namespace std;
vector <int> v;
long long ans=0;
int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x); 
	}
	sort (v.begin(),v.end());
	for (int i=0;i<n/2;i++)
		ans+=1ll*(v[i]+v[n-i-1])*(v[i]+v[n-i-1]);
	cout<<ans;
}