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
char d[10][10][10];
bool e[10][10][10];
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  for (int i=0;i<a;i++)
    for (int j=0;j<b;j++)
      for (int q=0;q<c;q++){
        cin>>d[i][j][q];
        e[i][j][q]=false;
  }
  int f,g;
  cin>>f>>g;
  if (d[0][f-1][g-1]=='#'){puts("0");return 0;}
  e[0][f-1][g-1]=true;
  for (int ma=0;ma<100;ma++){
  for (int i=0;i<a;i++)
    for (int j=0;j<100;j++)
      for (int q=0;q<b;q++)for(int k=0;k<c;k++){
      	if ((i != 0) and (e[i][q][k]==true)and(d[i-1][q][k]=='.')) e[i-1][q][k]=true;
      	if ((q != 0) and (e[i][q][k]==true)and(d[i][q-1][k]=='.')) e[i][q-1][k]=true;
      	if ((k != 0) and (e[i][q][k]==true)and(d[i][q][k-1]=='.')) e[i][q][k-1]=true;
      	if ((q != b-1) and (e[i][q][k]==true)and(d[i][q+1][k]=='.')) e[i][q+1][k]=true;
      	if ((k != c-1) and (e[i][q][k]==true)and(d[i][q][k+1]=='.')) e[i][q][k+1]=true;
        if ((i != a-1) and (e[i][q][k]==true)and(d[i+1][q][k]=='.')) e[i+1][q][k]=true;
	  }
  for (int i=a-1;i>=0;i--)
    for (int j=0;j<100;j++)
      for (int q=0;q<b;q++)for(int k=0;k<c;k++){
      	if ((i != 0) and (e[i][q][k]==true)and(d[i-1][q][k]=='.')) e[i-1][q][k]=true;
      	if ((q != 0) and (e[i][q][k]==true)and(d[i][q-1][k]=='.')) e[i][q-1][k]=true;
      	if ((k != 0) and (e[i][q][k]==true)and(d[i][q][k-1]=='.')) e[i][q][k-1]=true;
      	if ((q != b-1) and (e[i][q][k]==true)and(d[i][q+1][k]=='.')) e[i][q+1][k]=true;
      	if ((k != c-1) and (e[i][q][k]==true)and(d[i][q][k+1]=='.')) e[i][q][k+1]=true;
        if ((i != a-1) and (e[i][q][k]==true)and(d[i+1][q][k]=='.')) e[i+1][q][k]=true;
	  }
  }
  int num=0;
  for (int i=0;i<a;i++) for (int j=0;j<b;j++) for (int q=0;q<c;q++)
    if (e[i][j][q]==true) num++;
  cout<<num;
  return 0;
}