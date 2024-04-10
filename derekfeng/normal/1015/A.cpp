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
bool vis[104];
int main(){
	int n,m;
	cin>>n>>m;
	int ans=m;
	while (n--){
		int l,r;
		cin>>l>>r;
		for (int i=l;i<=r;i++){
			if (!vis[i])ans--;
			vis[i]=1;
		}
	}
	cout<<ans<<"\n";
	for (int i=1;i<=m;i++)
		if (!vis[i])
			cout<<i<<" "; 
}