//wish you spend a wonderful summer holiday lol by DerekFeng
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
int n;
int p[200004];
int a[200004];
vector <int> nah;
int searchroot(int x){
  if (a[x]) return searchroot(a[x]);
  else return x; 
}
int main(){
  cin>>n;
  int chap=-1;
  for(int i=1;i<=n;i++){
    cin>>p[i];
    if(p[i]==i) chap=i;
    if(i==searchroot(p[i])) nah.push_back(i);
    else a[i]=p[i];
  }
  int res;
  if (chap==-1) res=nah[nah.size()-1];
  else res=chap;
  for(int i=0;i<nah.size();i++) p[nah[i]]=res;
  cout<<nah.size()-(chap!=-1)<<endl;
  for(int i=1;i<=n;i++)
    cout<<p[i]<<" ";
  return 0;
}