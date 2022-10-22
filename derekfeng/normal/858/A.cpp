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
using namespace std;
int tmp(int a,int b)  
{         
  while(a != b)  {  
    if(a>b) a = a - b;    
    else{  
      b = b - a;  
    }  
  }  
  return a;  
}  
int main(){
  long long n,k,c10=1;
  cin>>n>>k;
  for (long long i=0;i<k;i++)
    c10 *= 10;
  cout<<n * c10 / tmp(n,c10);
  return 0;
}