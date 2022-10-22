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
long long a,b,big;
bool check(long long x){
	long long p=x*(x+1)/2;
	if (p<=a+b) return true;
	else return false;
}
void summon(long long x){
	if (x==0) cout<<0<<endl<<0;
	if (x==0) return;
	bool has[100004];
	long long ans[100004],nah;
	for (long long i=1;i<=x && (i+1)*i/2<=a;i++){
		ans[i]=i;
		nah=i;
		has[i]=1;
	}
	for (long long k=nah,mil=0;b!=0 && mil<a-nah*(nah+1)/2;k--,mil++){
		has[k]=0;
		ans[k]++;
		has[ans[k]]=1;
	}
	vector <long long> ans1,ans2;
	for (long long p=1;p<=x;p++){
		if (has[p]) ans1.push_back(p);
		else ans2.push_back(p);
	}
	cout<<ans1.size()<<endl;
	for (long long i=0;i<ans1.size();i++) cout<<ans1[i]<<" ";
	cout<<endl;
	cout<<ans2.size()<<endl;
	for (long long i=0;i<ans2.size();i++) cout<<ans2[i]<<" ";  
}
int main(){
	cin>>a>>b;
	for (long long i=0;i*(i+1)/2<=a+b;i++) big=i;
	long long l=0,r=big;
	while (r>l){
		long long mid=(l+r+1)/2;
		if (check(mid)) l=mid;
		else r=mid-1; 
	}
	summon(l);
	return 0;
}