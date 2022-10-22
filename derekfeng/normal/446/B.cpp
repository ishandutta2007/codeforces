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
typedef long long lint;
void solve(int n,int m,vector <lint> &rsum,int k,lint p,vector <lint> &ret){
  priority_queue<lint>pq;
  for (int i=0;i<n;i++) pq.push(rsum[i]);
  for (int i=0;i<k;i++){
    ret.push_back(pq.top());
    pq.push(pq.top()-(lint)m*p);
    pq.pop();
  }
}
int main(){
  int n,m,k,p;
  scanf("%d%d%d%d",&n,&m,&k,&p);
  vector <lint> rsum(n),csum(m);
  for (int y=0;y<n;y++)
    for (int x=0;x<m;x++){
	  int v;
	  scanf ("%d",&v);
	  rsum[y]+=v;
	  csum[x]+=v;
    }
  vector <lint> s1(1,0LL),s2(1,0LL);
  solve (n,m,rsum,k,p,s1);
  solve (m,n,csum,k,p,s2);
  partial_sum(s1.begin(),s1.end(),s1.begin());
  partial_sum(s2.begin(),s2.end(),s2.begin());
  lint ret=-1000000000000000000LL;
  for (int getrow=0;getrow<=k;getrow++){
  	const int getcol=k-getrow;
  	ret=max(ret,s1[getrow]+s2[getcol]-(lint)getrow*getcol*p);
  }
  cout<<ret;
  return 0;
}