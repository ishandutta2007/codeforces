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
#include <math.h>
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
#include <windows.h>
using namespace std;
int n,cnt[2],num=0;
string ans[2];
int main(){
	cin>>n;
	ans[0]="C";
	cnt[0]=1;
	for (int i=1;i<n;i++){
		if (ans[0][int(ans[0].size())-1]=='C'){
			ans[0]+='.';
			continue;
		}
		ans[0]+='C',cnt[0]++;
	}
	ans[1]=".";
	cnt[1]=0; 
	for (int i=1;i<n;i++){
		if (ans[1][int(ans[1].size())-1]=='.'){
			ans[1]+='C';
			cnt[1]++;
			continue;
		}
		ans[1]+='.';
	}
	for (int i=0;i<n;i++) num+=cnt[i%2];
	cout<<num<<endl;
	for (int i=0;i<n;i++)
		cout<<ans[i%2]<<endl;
}