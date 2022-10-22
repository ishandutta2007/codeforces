//F*** EXAM
//OH
//F***
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
int n,c;
int p[54],t[54];
int main(){
	cin>>n>>c;
	for (int i=0;i<n;i++)
		cin>>p[i];
	for (int i=0;i<n;i++)
		cin>>t[i];
	int num1=0,num2=0,times=0;
	for (int i=0;i<n;i++){
		times+=t[i];
		num1+=max(0,p[i]-times*c);
	}
	times=0;
	for (int i=n-1;i>=0;i--){
		times+=t[i];
		num2+=max(0,p[i]-times*c);
	}
	if (num1>num2) cout<<"Limak";
	else if (num2>num1) cout<<"Radewoosh";
	else cout<<"Tie";
}