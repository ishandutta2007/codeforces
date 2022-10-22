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
int n;
int a[100003];
priority_queue<pii> q;
typedef pair<int,pii> p3;
int b[3];
int main(){
  cin>>n;
  for (int i=0;i<n;i++) scanf("%d",a+i);
  sort(a,a+n);
  for (int i=0;i<n;){
    int j=i;
    while (j<n && a[j]==a[i]) j++;
    q.push(pii(j-i,a[i]));
    i=j;
  }
  vector <p3> v;
  while (q.size()>2){
    pii v1=q.top();q.pop();
    pii v2=q.top();q.pop();
    pii v3=q.top();q.pop();
    b[0]=v1.second;
    b[1]=v2.second;
    b[2]=v3.second;
    sort (b,b+3);
    v.push_back(p3(b[2],pii(b[1],b[0])));
    v1.first--;if (v1.first) q.push(v1);
    v2.first--;if (v2.first) q.push(v2);
    v3.first--;if (v3.first) q.push(v3);
  }
  cout<<v.size()<<endl;
  for (int i=0;i<v.size();i++)
    printf("%d %d %d\n",v[i].first,v[i].second.first,v[i].second.second);
  return 0;
}