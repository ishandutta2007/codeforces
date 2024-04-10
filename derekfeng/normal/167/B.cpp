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
    int n,l,k,p[203],a[203];
    double dp[203][203][403],ans=0.0;
    int main(){
    	cin>>n>>l>>k;
    	for (int i=1;i<=n;i++) scanf ("%d",&p[i]);
    	for (int i=1;i<=n;i++) scanf ("%d",&a[i]);
    	dp[0][0][k+200]=1.0;
    	for (int i=1;i<=n;i++) for (int j=0;j<=i;j++) for (int q=0;q<=400;q++){
    		if (j>0 && q+a[i]>=0) dp[i][j][min(q+a[i],400)]+=dp[i-1][j-1][q]*((double)p[i]/100.0);
    		dp[i][j][q]+=dp[i-1][j][q]*(1.0-(double)p[i]/100.0);
    	}
    	for (int i=l;i<=n;i++)for(int j=200;j<=400;j++)ans+=dp[n][i][j];
    	printf("%.12lf",ans);
    }