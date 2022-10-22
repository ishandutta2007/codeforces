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
int is_prime[120000];
int prime[120000];
int cntP=0;
void produce_prime(){
  memset (is_prime,0,sizeof(is_prime));
  is_prime[1]=1;
  for (int i=2;i<120000;i++){
    if(is_prime[i]==0){
      prime[cntP++]=i; 
	  int j=i+i;
	  while (j<120000){
	    is_prime[j]=1;
	    j+=i;
	  }
    }
  }
}
int thenearest(int i){
  return *lower_bound(prime,prime+cntP,i)-i;
}
long long a[504][504];
long long b[504][504];
int main(){
  produce_prime();
  long long ans=2e9;
  int n,m;
  cin>>n>>m;
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++){
      cin>>a[i][j];
      b[i][j]=thenearest(a[i][j]);
  }
  for (int i=0;i<n;i++){
    long long cnt=0;
    for (int j=0;j<m;j++)
      cnt+=b[i][j];
    ans=min(ans,cnt);
  }
  for (int j=0;j<m;j++){
    long long cnt=0;
    for (int i=0;i<n;i++)
      cnt+=b[i][j];
    ans=min(ans,cnt);
  }
  cout<<ans;
  return 0;
}