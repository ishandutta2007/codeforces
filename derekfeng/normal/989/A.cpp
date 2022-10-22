//this is made by DerekFeng,a codeforces user
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
using namespace std;
int main(){
  string s;
  cin>>s;
  for (int i=2;i<s.size();i++){
    int j=i-2;
    bool a=false,b=false,c=false;
    for (int q=j;q<=i;q++){
      if (s[q]=='A') a=true;
      if (s[q]=='B') b=true;
      if (s[q]=='C') c=true;
	}
    if (a&&b&&c){cout<<"Yes";return 0;}
  }
  cout<<"No";
  return 0;
}