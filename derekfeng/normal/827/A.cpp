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
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
int n;
int d[2000004];
int o[2000004];	
string s[200004];
string ans;
int k,num=0;
int main(){
	cin>>n;
	for (int i=1;i<=2e6;i++) d[i]=i,o[i]=-1; 
	for (int i=0;i<n;i++){
		cin>>s[i];
		int y=s[i].size();
		scanf ("%d",&k);
		for (int j=0;j<k;j++){
			int x;
			scanf ("%d",&x);
			if (d[x]<=x+y-1){
				d[x]=x+y-1;
				o[x]=i;
			}
			num=max(num,x+y-1);
		}
	}
	int now=0;
	for (int i=1;i<=num;i++){
		if (now>=d[i]) continue;
		else{
			if (o[i]==-1){ans+="a",now++;}
			else{ans+=s[o[i]].substr(s[o[i]].size()-d[i]+now);now=d[i];}
		}
	}
	printf("%s",ans.c_str());
}