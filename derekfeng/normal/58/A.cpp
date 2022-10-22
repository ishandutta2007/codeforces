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
#include <windows.h> 
using namespace std;
char a[5]={'h','e','l','l','o'};
int main(){
	string s;
	cin>>s;
	for (int i=0,j=0;i<s.size();i++){
		if (s[i]==a[j]){
			j++;
			if (j==5){
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}