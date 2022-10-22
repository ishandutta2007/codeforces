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
int q;
int nm[50004],mm[50004];
char cc[400005];
int main(){
	cin>>q;
	while (q--){
		char c;
		int n,m;scanf ("%d%d",&n,&m);
		for (int i=1;i<=n;i++) nm[i]=0;
		for (int i=1;i<=m;i++) mm[i]=0;
		for (int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			cin>>c;if (c=='*') nm[i]++,mm[j]++;
			cc[(i-1)*m+j]=c;
		}
		int ans=1e9;
		for (int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			if(cc[(i-1)*m+j]!='*')ans=min(ans,n-nm[i]+m-mm[j]-1);
			else ans=min(n-nm[i]+m-mm[j],ans);
		}
		cout<<ans<<"\n";
	}
}