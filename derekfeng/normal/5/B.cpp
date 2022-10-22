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
vector <string> alori;
vector <int> alsize;
string s;
int main(){
  int ai=1,every=0,cnt=0;
  while (getline(cin,s)){
  	alori.push_back(s);
  	alsize.push_back(s.size());
  	cnt=max(alsize[alsize.size()-1],cnt);
  }
  for (int i=0;i<cnt+2;i++) cout<<"*";
  cout<<endl;
  for (int i=0;i<alori.size();i++){
    every=cnt-alori[i].size();
    if (every % 2==0){
      cout<<"*";
      for (int j=0;j<every/2;j++) cout<<" ";
      cout<<alori[i];
      for (int j=0;j<every/2;j++) cout<<" ";
      cout<<"*";
    }
    else{
      if (ai%2==0){
      	cout<<"*";
        for (int j=0;j<every/2+1;j++) cout<<" ";
        cout<<alori[i];
        for (int j=0;j<every/2;j++) cout<<" ";
        cout<<"*";
	  }
	  if (ai%2==1){
	  	cout<<"*";
	  	for (int j=0;j<every/2;j++) cout<<" ";
	  	cout<<alori[i];
	  	for (int j=0;j<every/2+1;j++) cout<<" ";
	  	cout<<"*";
	  }
	  ai++;
    }
    cout<<endl;
  }
  for (int i=0;i<cnt+2;i++) cout<<"*";
  return 0;
}