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
int main(){
	int a,b,ans=0;
	cin>>a>>b;
	int cha=max(a,b);
	for (int i=1;i<=6;i++){
		if (i>=cha) ans++;		
	}
	if (ans==1) cout<<"1/6";
	if (ans==2) cout<<"1/3";
	if (ans==3) cout<<"1/2";
	if (ans==4) cout<<"2/3";
	if (ans==5) cout<<"5/6";
	if (ans==6) cout<<"1/1";
	return 0;
}