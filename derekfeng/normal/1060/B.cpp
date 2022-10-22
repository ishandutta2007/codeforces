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
long long x,w=0,sum;
int p[12];
bool o[13];
int main(){
	cin>>x;
	while (x>0){
		sum+=x%10;
		w++;
		p[w]=x%10;
		x/=10;
	}
	sum+=(w-1)*9;
	for (int i=1;i<w;i++)
		if (p[i]!=9 || o[i-1]){
			o[i]=1;
		}
		else{
			sum-=9;
		}
	cout<<sum;
	return 0;
}