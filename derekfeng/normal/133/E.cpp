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
#define FOR(i,a,b) for (int i(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
string s;
int n;
int best=0;
int a[111][55][211][3];
void go(int pos,int change,int x,int dx){
	if (a[pos][change][x+100][dx+1]) return;
	a[pos][change][x+100][dx+1]=1;
	if (pos==s.size()){
		if (change==0) best=max(best,abs(x));
		return;
	}
	REP(i,change+1){
		int val=(s[pos]=='F');
		if (i%2) val^=1;
		go(pos+1,change-i,x+(val==1?dx:0),dx*(val==0?-1:1));
	}
}
int main(){
	cin>>s>>n;
	go(0,n,0,1);;
	cout<<best;
}