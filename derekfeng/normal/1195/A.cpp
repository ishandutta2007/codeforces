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
int n,k,cnt=0,x,ans=0; 
int t[1003];
int main(){
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>x;t[x]++;
		if (t[x]==2 && cnt<(n+1)/2) ans+=2,t[x]=0,cnt++;
	}
	if (cnt<(n+1)/2){
		for (int i=1;i<=k && cnt<(n+1)/2;i++)ans++,cnt++;
	}
	cout<<ans;
}