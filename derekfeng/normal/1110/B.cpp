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
int n,m,k;
int b[100004];
vector <int> v;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n>>m>>k;
	for (int i=0;i<n;i++){
		cin>>b[i];
		if (i>0)v.push_back(b[i]-b[i-1]-1);
	}
	int ans=b[n-1]-b[0]+1;
	sort (v.begin(),v.end(),cmp);
	for (int i=0;i<k-1;i++)
		ans-=v[i];
	cout<<ans;
}