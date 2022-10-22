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
typedef pair<int,int> pii;
#define CL(a,b) memset(a,b,sizeof(a))
int n;
int a[303][303];
int b[303][303];
int p[303];
int res[303];
int c[303];
set <pii> s;
int main(){
  cin>>n;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%d",&a[i][j]),a[i][j]--,b[i][a[i][j]]=1000-j;
  for (int i=0;i<n;i++) scanf("%d",&p[i]),p[i]--;
  CL(res,-1);
  CL(c,-1);
  for (int i=0;i<n;i++){
    int pos=-1;
    for (int j=0;j<n;j++) if (p[j]==i) pos=j;
    s.insert(pii(pos,i));
    pii x=*s.begin();
    for (int j=0;j<n;j++){
	  if (x.second!=j){
	    if (b[j][x.second]>c[j]){
		  c[j]=b[j][x.second];
		  res[j]=i;
	    }
	  }
	  if (x.second==j){
	    if (s.size()>1){
		  pii y=*(++s.begin());
		  if (b[j][y.second]>c[j]){
		    c[j]=b[j][y.second];
		    res[j]=i;
		  }
	    }
	  }
    }
  }
  for (int i=0;i<n;i++)
    cout<<res[i]+1<<" ";
  return 0;
}