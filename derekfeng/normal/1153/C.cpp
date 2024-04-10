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
string s;
int now=0,num=0,num11=0;
int main(){
	int n;
	cin>>n;
	cin>>s;
	for (int i=0;i<n;i++)
		if (s[i]=='(') num++;
	int qqq=0,num0=n/2-num;
	if (num>n/2){
		return !printf(":(");
	} 
	for (int i=0;i<n;i++){
		if (s[i]=='(') now++;
		if (s[i]==')') now--;
		if (s[i]=='?'){
			qqq++;
			if (qqq<=num0) s[i]='(',now++;
			else now--,s[i]=')';
		}
		if (now<0) return !printf(":(");
		if (now==0 && i!=n-1) return !printf(":("); 
	}
	if (now>0) return !printf(":(");
	cout<<s;
}