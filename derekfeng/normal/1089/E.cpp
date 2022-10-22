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
int n;
typedef pair<int,int> pii;
string to(int x,int y){
	return string(1,'a'+x)+string(1,'1'+y);
}
int b[8][8];
vector <pii> st;
void nxt(int &x,int &y){
	if (y==7) ++x,y=0;
	else ++y;
}
bool go(int x,int y,int rem){
	if (x==7 && y==7){
		if (rem==0){
			return true;
		}else{
			return false;
		}
	}
	if (rem==0) return false;
	int sx=x,sy=y;
	x=0;
	y=0;
	while (1){
		nxt(x,y);
		if (b[x][y]==0 && (x==sx || y==sy)){
			st.push_back(make_pair(x,y));
			b[x][y]=1;
			if (go(x,y,rem-1)) return true;
			b[x][y]=0;
			st.pop_back();
		}
		if (x==7 && y==7) break; 
	}
	return false;
}
int main(){
	cin>>n;
	st.push_back(make_pair(0,0));
	assert(go(0,0,n));
	for (int i=0;i<st.size();i++)
		cout<<to(st[i].first,st[i].second)<<" ";
	return 0;
}