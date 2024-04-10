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
long long g[5][5];
int main(){
  for (int i=0;i<5;i++)
    for (int j=0;j<5;j++){
	  cin>>g[i][j];
    }
  long long ans=0;
  for (int i=0;i<5;i++)
  for (int j=0;j<5;j++)
  for (int k=0;k<5;k++)
  for (int q=0;q<5;q++)
  for (int p=0;p<5;p++){
  	if (i!=j && i!=k && i!=q && i!=p
	 && j!=k && j!=q && j!=p
	 && k!=q && k!=p
	 && q!=p);
    else continue;
    long long cnt=0;
    cnt+=g[i][j]+g[j][i]+g[k][q]+g[q][k]+g[j][k]+g[k][j]+g[q][p]+g[p][q];
    cnt+=g[k][q]+g[q][k]+g[q][p]+g[p][q];
    ans=max(ans,cnt);
  }
  cout<<ans;
  return 0;
}