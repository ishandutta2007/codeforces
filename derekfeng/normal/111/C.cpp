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
int dir[5][2]={{0,0},{1,1},{1,0},{1,-1},{2,0}};
int n,m;
typedef pair<pair<int,int>,int> mpair;
map <mpair,int> M;
int rec(int x,int y,int mask){
	if (m<y) return rec(x+1,1,mask>>m);
	if (x==n+1) return 0;
	mpair p=make_pair(make_pair(x,y),mask);
	if (M.find(p)!=M.end())	return M[p];
	bool flag=1;
	for (int i=0;i<5;i++){
		int v=dir[i][1]+y;
		if (v<1 || v>m || (i==4 && x==n)) continue;
		flag&=((mask&(1<<(dir[i][0]*m+v-1)))==1);
	}
	if (flag) return M[p]=rec(x,y+1,mask);
	int anss=1000;
	if ((mask&(1<<(y-1)))==0 ||(x==n && y!=1 && (mask&(1<<(m+y-2)))==0)||(x==n && y==m && (mask&(1<<(2*m-1)))==0));
	else anss=rec(x,y+1,mask);
	for (int i=0;i<5;i++){
		int v=dir[i][1]+y;
		if (v<1 || v>m) continue;
		mask|=(1<<(dir[i][0]*m+v-1));
	}
	anss=min(anss,rec(x,y+1,mask)+1);
	return M[p]=anss;
}
int main(){
	int kilp=0;
	cin>>n>>m;
	if (n<m) swap(n,m);
	for (int i=0;i<m;i++) 
		kilp|=(1<<i);
	int ans=rec(1,1,kilp);
	cout<<n*m-ans;
}