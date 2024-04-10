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
int letters[140];
int main(){
  string s1,s2;
  getline (cin,s1);
  getline (cin,s2);
  for (int i=0;i<s1.size();i++)
    if (s1[i]!=' ')
      letters[s1[i]]++;
  for (int j=0;j<s2.size();j++)
    if (s2[j]!=' ')
      letters[s2[j]]--;
  for (int i=0;i<140;i++)
    if (letters[i]<0){
      cout<<"NO";
      return 0;
	}
  cout<<"YES";
  return 0;
}