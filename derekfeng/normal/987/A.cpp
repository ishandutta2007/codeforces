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
#include  <list>
#include  <utility>
#include  <memory>
#include  <cstring>
#include  <fstream>
#include  <numeric>
using namespace std;
string s[6]={"Power","Space","Reality","Soul","Time","Mind"};
bool so[6];
string t;
int main(){
  long long n,ans=0;
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>t;
  	if (t=="purple") so[0]=true;
  	if (t=="blue") so[1]=true;
  	if (t=="red") so[2]=true;
  	if (t=="orange") so[3]=true;
  	if (t=="green") so[4]=true;
  	if (t=="yellow") so[5]=true;
  }
  for (int i=0;i<6;i++)
    if (!so[i]) ans++;
  cout<<ans<<endl;
  for (int i=0;i<6;i++){
  	if (!so[i]) cout<<s[i]<<endl;
  }
  return 0;
}