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
int main(){
  string s;
  cin>>s;
  int p=0;
  while (p<s.size()){
    if (s[p]!='W'||s[p+1]!='U'||s[p+2]!='B'){cout<<s[p];p++;continue;}
    if (s[p]=='W' && s[p+1]=='U' && s[p+2]=='B' && p!=0 && (s[p-1]!='B' || s[p-2]!='U' || s[p-3]!='W')){cout<<" ";p+=3;continue;}
    p+=3;
  }
  return 0;
}