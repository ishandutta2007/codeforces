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
#include <numeric>
#include <memory>
#include <cstring> 
#include <fstream>
#include <assert.h>
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
int n,r,anss=1e9,now;
int ans[2]={'B','T'};
string ress;
bool yes(int x,int y,int lefts){
	if (x>y) return yes(y,x,lefts);
	if (lefts==0 && x==0 && y==1) return 1; 
	if (x==0 || left<=0) return 0;
	int p=y/x;
	return yes(x,y%x,lefts-p);
}
int dfs(int x,int y,int left){
	if (x>y) return dfs(y,x,left);
	if (left==0) return 0;
	int p=y/x;
	if (y%x==0) return p-2;
	int num=dfs(x,y%x,left-p);
	return num+p-1;
}
int awsl(int x,int y,int left){
	if (x>y) return awsl(y,x,left);
	if (left==0 && x==0 && y==1) return 0;
	int p=y/x;
	if (y%x==0){
		ress+='T';
		for (int i=01;i<p;i++)ress+='B';
		return 0;
	}
	int nah=awsl(x,y%x,left-p);
	for (int i=0;i<p;i++) ress+=ans[1^nah];
	return nah^1;
}
int main(){
	cin>>n>>r;
	if (n==1 && r==1){
		cout<<"0\nT";return 0;
	}
	for (int i=1;i<=r;i++)if(yes(i,r,n)){
		int o=dfs(i,r,n);
		if (o<anss){
			anss=o;
			now=i;
		}
	}
	if (anss==1e9){
		cout<<"IMPOSSIBLE";return 0;
	}
	awsl(now,r,n);
	cout<<anss<<"\n";
	cout<<ress;
}