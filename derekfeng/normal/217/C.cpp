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
int A[20][20],O[20][20],X[20][20],n;
char buf[1000005];string s;
int myl[1000005],myr[1000005];
int func(int x){
	if (s[x]!='('){
		if (s[x]=='0') return 1;
		if (s[x]=='1') return 8;
		return 6;
	}
	int L=x+1;
	int R=((s[L]=='(')?myr[L]+1:L+1)+1;
	int xx=func(L),yy=func(R);
	char oper=s[R-1];
	if (oper=='&') return A[xx][yy];
	if (oper=='|') return O[xx][yy];
	return X[xx][yy];
}
int parse(){
	int N=s.size();vector<int>v;
	for (int i=0;i<N;i++){
		if (s[i]=='('){
			v.push_back(i); 
		}else if (s[i]==')'){
			int j=v[v.size()-1];
			v.pop_back();
			myl[i]=j;
			myr[j]=i;
		}
	}
	return func(0);
}
int main(){
	for (int i=0;i<16;i++)for(int j=0;j<16;j++)for(int x1=0;x1<2;x1++)for(int x2=0;x2<2;x2++)for(int y1=0;y1<2;y1++)for(int y2=0;y2<2;y2++){
		if (x1==0 && x2==0 && !(i&1)) continue;
		if (x1==0 && x2==1 && !(i&2)) continue;
		if (x1==1 && x2==0 && !(i&4)) continue;
		if (x1==1 && x2==1 && !(i&8)) continue;		
		if (y1==0 && y2==0 && !(j&1)) continue;
		if (y1==0 && y2==1 && !(j&2)) continue;
		if (y1==1 && y2==0 && !(j&4)) continue;
		if (y1==1 && y2==1 && !(j&8)) continue;
		int z1,z2;
		z1=x1&y1,z2=x2&y2;
		if (z1==0 && z2==0) A[i][j]|=1;
		if (z1==0 && z2==1) A[i][j]|=2;
		if (z1==1 && z2==0) A[i][j]|=4;
		if (z1==1 && z2==1) A[i][j]|=8;
		z1=x1|y1,z2=x2|y2; 
		if (z1==0 && z2==0) O[i][j]|=1;
		if (z1==0 && z2==1) O[i][j]|=2;
		if (z1==1 && z2==0) O[i][j]|=4;
		if (z1==1 && z2==1) O[i][j]|=8;
		z1=x1^y1,z2=x2^y2;
		if (z1==0 && z2==0) X[i][j]|=1;
		if (z1==0 && z2==1) X[i][j]|=2;
		if (z1==1 && z2==0) X[i][j]|=4;
		if (z1==1 && z2==1) X[i][j]|=8;
	}
	cin>>n;scanf("%s",buf);s=buf;
	int ans=parse();
	if (ans&6) cout<<"YES";
	else cout<<"NO";
}