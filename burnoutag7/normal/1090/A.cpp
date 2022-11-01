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
typedef long long ll;
int n,bigst[200005],m[200005],o[200005];
bool cmp(int a,int b){
	return bigst[a]<bigst[b];
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++) o[i]=i;
	for (int i=0;i<n;i++){
		cin>>m[i];
		for (int j=0;j<m[i];j++){
			int x;
			cin>>x;
			bigst[i]=max(bigst[i],x);
		}
	}
	sort (o,o+n,cmp);
	int op=m[o[0]];
	ll ans=0;
	for (int i=1;i<n;i++){
		ans+=1ll*op*(bigst[o[i]]-bigst[o[i-1]]);
		op+=m[o[i]];
	}
	cout<<ans;
	return 0;
}