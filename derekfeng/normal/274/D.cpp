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
const int N=200010;
vector <int> m[N];
int a[N],u[N],s[N],c,q[N];
bool cmp(int i,int j){
  return a[i]<a[j];
}
bool dfs(int i){
  int j;
  u[i]=1;
  for (j=0;j<m[i].size();j++){
    if (u[m[i][j]]==1) return 1;
    else if (!u[m[i][j]] && dfs(m[i][j])) return 1;
  }
  u[i]=2;
  s[c++]=i;
  return 0;
}
int main(){
  int n,k,i,j,l,t;
  cin>>n>>k;
  for (i=0,t=k;i<n;i++){
    for (j=0;j<k;j++){cin>>a[j];u[j]=j;}
    sort (u,u+k,cmp);
    for (j=0;j<k && a[u[j]]==-1;j++);
    for (t++;j<k;t++,j+=l)
	  for (l=0;j+l<k && a[u[j]]==a[u[j+l]];l++){
	    m[t-1].push_back(u[j+l]),m[u[j+l]].push_back(t);
	  }
  }
  for (i=0;i<t;u[i]=0,i++);
  for (i=0;i<t;i++)
    if (!u[i] && dfs(i)) break;
  if (i<t) cout<<"-1";
  else{
    for (i=t-1;i>=0;i--)
      if (s[i]<k) cout<<s[i]+1<<" ";
  }
  return 0;
}