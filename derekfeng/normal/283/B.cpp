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
#include<list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
LL a[200010];
LL dp[2][200010];
int vis[2][200010];
LL go(int s,int x){
  if (x<=0 || x>n) return 0;
  if (x==1 || vis[s][x]==1) return -1;
  LL &ret=dp[s][x];
  if (vis[s][x]==2) return ret;
  vis[s][x]=1;
  long long val=go(s^1,(s==0)?x+a[x]:x-a[x]);
  vis[s][x]=2;
  if (val==-1) return ret=val;
  else return ret=val+a[x];
}
int main(){
  scanf ("%d",&n);
  for (int i=2;i<=n;i++) cin>>a[i];
  for (int i=1;i<n;i++){
    long long res=go(1,i+1);
    if (res==-1) printf("-1\n");
    else cout<<res+i<<endl;
  }
  return 0;
}