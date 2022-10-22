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
	int n;
	cin>>n;
	int x=0,y=0;
	for (int i=0;i<n;i++){
		char c;
		cin>>c;
		x+=(c=='A');
		y+=(c=='D');
	}
	if (x==y)
		cout<<"Friendship";
	if (x<y)
		cout<<"Danik";
	if (x>y)
		cout<<"Anton";
	return 0;
}