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
int n,q;
string s;
int main(){
	cin>>n>>s>>q;
	while (q--){
		int x;
		char c;
		cin>>x>>c;
		int ans=0,l=0,r=0;
		for (int i=0;i<s.size();i++){
			if (s[i]!=c) r++;
			while (r>x){
				if (s[l]!=c) r--;
				l++;
			}
			ans=max(ans,i-l+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}