//NOIP 2018
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
int n,num=0;
int a[13];
int main(){
	cin>>n;
	if (n==1){
		puts("-1");
		return 0;
	}
	for (int i=0;i<n;i++){
		cin>>a[i];
		num+=a[i];
	}
	for (int i=0;i<n;i++){
		if (num-a[i]!=a[i]){
			cout<<1<<endl<<i+1;
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}