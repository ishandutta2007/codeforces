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
int n;
int a[103];
int main(){
	cin>>n;
	int _res=-110,num_1=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i]==1) num_1++;
	}
	for (int i=0;i<n;i++)
		for (int j=i;j<n;j++){
			int num0=0,num1=0;
			for (int k=i;k<=j;k++)
				if (a[k]==0) num0++;
				else num1++;
			_res=max(_res,num0-num1);
		}
	cout<<num_1+_res;
	return 0;
}