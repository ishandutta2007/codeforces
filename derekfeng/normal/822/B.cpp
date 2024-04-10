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
int n,m,ans=1e9,now=-1;
string s,t;
int main(){
	cin>>n>>m>>s>>t;
	s="0"+s,t="0"+t;
	for (int i=1;i<=m-n+1;i++){
		int res=0;
		for (int q=1;q<=n;q++)
			if (s[q]!=t[q+i-1]) res++;
		if (res<ans) ans=res,now=i; 
	}
	cout<<ans<<"\n";
	for (int i=1;i<=n;i++)
		if (s[i]!=t[i+now-1]) cout<<i<<" ";
}