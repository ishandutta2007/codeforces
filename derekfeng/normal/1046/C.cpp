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
bool cmp(int a,int b){
	return a>b;
}
int N,a[200004],n[200004],K;
vector <int> ww;
int fut;
bool check(int x){
	for (int i=x,j=N;i<N;i++,j--)
		if (ww[i]+n[j]>fut) return false;
	return true;
}
int main(){
	cin>>N>>K;
	ww.push_back(1e9);
	for (int i=1;i<=N;i++){
		cin>>a[i];
		if (i!=K)ww.push_back(a[i]);
	}
	sort (ww.begin(),ww.end(),cmp);
	for (int i=1;i<=N;i++)
		cin>>n[i];
	sort (n+1,n+1+N,cmp);
	fut=a[K]+n[1];
	int l=1,r=N,mid=(l+r)/2;
	while (l<r){
		mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<r;
	return 0;
}