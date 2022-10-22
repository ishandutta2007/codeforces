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
using namespace std;
int x;
int a[103];
vector <int> a1[103];
vector <int> a2[103];
bool a3[103];
bool a4[103];
void dfs(long long i){
  a3[i]=true;
  for (int j=0;j<a2[i].size();j++){
    int p=a2[i][j];
    if (!a4[p]){
      a4[p]=true;
      for (int q=0;q<a1[p].size();q++)
        dfs(a1[p][q]);
	}
  }
}
int main(){
  int n,m,ans=0;
  cin>>n>>m;
  for (int i=0;i<n;i++){
    cin>>a[i];
    if (a[i]==0){ans++;a4[i]=true;}
    for (int j=0;j<a[i];j++){
	  cin>>x;
      a1[i].push_back(x);
      a2[x].push_back(i);
    }
  }
  if (ans==n){cout<<ans;return 0;}
  for (int i=1;i<=m;i++)
    if (!a3[i] && (!a2[i].empty())){
      dfs(i);
      ans++;
    }
  ans--;
  cout<<ans;
  return 0;
}