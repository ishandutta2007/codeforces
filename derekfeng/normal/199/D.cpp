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
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
queue<int> qx,qy;
int d[2][110000];
char s[2][110000];
int n,k;
int main(){
  gets(s[0]);
  sscanf(s[0],"%d %d",&n,&k);
  gets(s[0]);
  gets(s[1]);
  memset(d,63,sizeof(d));
  d[0][0] = 0;
  qx.push(0);
  qy.push(0);
  for (;qx.size();){
    int x = qx.front();
    int y = qy.front();
	qx.pop();qy.pop();
    if (d[y][x]>x) continue;
    if (x+k>=n){cout<<"YES";return 0;}
    if (s[y][x+1]=='-'){
      if (d[y][x+1]>d[y][x]+1){
        d[y][x+1]=d[y][x]+1;
        qx.push(x+1);
        qy.push(y);
	  }  
    }
    if (x>0 && s[y][x-1]=='-'){
      if (d[y][x-1]>d[y][x]+1){
        d[y][x-1]=d[y][x]+1;
        qx.push(x-1);
        qy.push(y);
      }   
    }
    if (s[y^1][x+k]=='-'){
      if (d[y^1][x+k]>d[y][x]+1){
        d[y^1][x+k]=d[y][x]+1;
        qx.push(x+k);
        qy.push(y^1);
      } 
    }
  }
  cout<<"NO";
  return 0;
}