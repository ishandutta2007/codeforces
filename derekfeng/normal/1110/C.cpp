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
int q;
int num[27];
map <int,int> mp; 
int main(){
	cin>>q;
	for (int i=0;i<26;i++) num[i]=(1<<(i+1))-1;
	while (q--){
		int a;
		cin>>a;
		int n=0;
		while (num[n]<a) n++;
		if (num[n]==a){
			int ans=1;
			for (int i=2;i*i<=a;i++)
				if (a%i==0){
					ans=max(ans,a/i);
					break;
				}
			cout<<ans<<endl;
		}
		else cout<<num[n]<<endl;
	}
}