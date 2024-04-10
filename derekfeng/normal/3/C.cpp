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
#define two(x) (1<<(x))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++) 
string board[3];
int win(char ch){
	int i,j,mask=(1<<9)-1,cnt=0;
	vector <int> v;
	REP(i,3) v.push_back(two(i*3)+two(i*3+1)+two(i*3+2)); 
	REP(i,3) v.push_back(two(i)+two(i+3)+two(i+6)); 
	v.push_back(two(0)+two(4)+two(8)); 
	v.push_back(two(2)+two(4)+two(6)); 
	int mask2=0;
	REP(i,3) REP(j,3) if (board[i][j]==ch) mask2|=two(i*3+j);
	REP(i,v.size()) if ((mask2&v[i])==v[i]){
		cnt++;
		mask&=v[i];
	}
	if (cnt==0) return 0;
	if (mask==0) return 2;
	return 1;
}
int count(char ch){
	int i,j,ans=0;
	REP(i,3) REP(j,3) if (board[i][j]==ch) ans++;
	return ans;
}
string func(void){
	int A=count('X'),B=count('0');
	if (A<B || A>B+1) return "illegal"; 
	int player=((A==B)?0:1);
	int wA=win('X'),wB=win('0');
	if (wA==2 || wB==2 || (player==0 && wA==1) || (player==1 && wB==1)) return "illegal";
	if (wA==1) return "the first player won";
	if (wB==1) return "the second player won";
	if (A+B==9) return "draw";
	if (player==0) return "first";
	return "second";
}
int main(){
	int i;
	REP(i,3) cin>>board[i];
	string ans=func();
	cout<<ans;
}