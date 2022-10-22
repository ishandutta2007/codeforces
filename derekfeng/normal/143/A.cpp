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
  int a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  for (int i=1;i<=9;i++)
    for (int j=1;j<=9;j++)
      for (int q=1;q<=9;q++)
        for (int k=1;k<=9;k++)
          if (i!=j && i!=q && i!=k && j!=q && j!=k && q!=k && a==i+j && b==q+k && c==i+q && d==j+k && e==i+k && f==j+q){
            cout<<i<<" "<<j<<endl<<q<<" "<<k;
            return 0;
		  }
  puts("-1");
  return 0;
}