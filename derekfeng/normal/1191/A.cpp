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
int x;
string ans[4]={"D","A","C","B"};
int good[4]={0,3,1,2};
int main(){
	cin>>x;
	int res=x%4,now=0;
	for (int i=x;i<=x+2;i++){
		if (good[i%4]>good[res]) res=i%4,now=i-x;
	}
	cout<<now<<" "<<ans[res];
}