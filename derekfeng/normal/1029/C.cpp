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
#define conti continue
int lt[300005],rt[300005];
int n;
multiset <int> l,r;
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>lt[i]>>rt[i];
		l.insert(lt[i]);
		r.insert(rt[i]);
	}
	int ans=0;
	for (int i=0;i<n;i++){
		l.erase(l.find(lt[i]));
		r.erase(r.find(rt[i]));
		ans=max(ans,*r.begin()-*l.rbegin());
		l.insert(lt[i]);
		r.insert(rt[i]);
	}
	cout<<ans;
	return 0;
}