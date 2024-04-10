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
typedef long long ll;
int ans=0;
ll n;int m;ll k;ll p[100004];
int hasgo=0;
bool yes[100004];
int main(){
	cin>>n>>m>>k;
	for (int i=0;i<m;i++) cin>>p[i];
	for (int i=0;i<m;i++) if (!yes[i]){
		int x=i;
		while ((p[i]-hasgo+k-1)/k==(p[x]-hasgo+k-1)/k) yes[x]=1,x++;
		hasgo+=x-i;
		ans++;
	}
	cout<<ans;
}