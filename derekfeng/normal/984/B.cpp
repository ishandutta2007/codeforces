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
char a[103][103];
bool bod(int i,int j,bool flag){
  char bd='0';
  if (a[i-1][j]=='*') bd++;
  if (a[i-1][j-1]=='*') bd++;
  if (a[i-1][j+1]=='*') bd++;
  if (a[i][j-1]=='*') bd++;
  if (a[i][j+1]=='*') bd++;
  if (a[i+1][j]=='*') bd++;
  if (a[i+1][j-1]=='*') bd++;
  if (a[i+1][j+1]=='*') bd++;
  if (bd != a[i][j])return true;
  return false;
}
int main(){
  bool flag=true;
  int n,m;
  cin>>n>>m;
  for (int i=0;i<n;i++){
    cin>>a[i];
    for (int j=0;j<m;j++)
      if (a[i][j]=='.')
        a[i][j]='0';
  }
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
      if (a[i][j]!='*')
      	if (bod(i,j,flag)){
      	  cout<<"NO";
		  return 0;  
		}
  cout<<"YES";
  return 0;
}