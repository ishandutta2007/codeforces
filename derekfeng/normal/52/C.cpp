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
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
int n,n_=1;
ll num[600004];
ll dat[600004];
char c[25];
ll rmq(int l,int r,int a,int b,int id){
	if (r<a || l>b) return 1e18;
	if (r<=b && l>=a){
		ll ans=num[id];
		if (id!=0) while(1){
			id=(id-1)/2;
			ans+=dat[id];
			if (id==0) break;
		}
		return ans;
	}
	return min(rmq(l,(r+l)/2,a,b,id*2+1),rmq((l+r)/2+1,r,a,b,id*2+2));
}
void inc(int l,int r,int a,int b,int id,ll t){
	if (r<a || l>b) return;
	if (r<=b && l>=a){
		dat[id]+=t;
		num[id]+=t;
		if (id!=0) while (1){
			id=(id-1)/2;
			num[id]=min(num[id*2+1],num[id*2+2])+dat[id]; 
			if (id==0) break;
		}
		return;
	}
	inc(l,(l+r)/2,a,b,id*2+1,t);
	inc((l+r)/2+1,r,a,b,id*2+2,t);
}
ll opt1(int a,int b){
	if (a>b) return min(rmq(0,n_-1,0,b,0),rmq(0,n_-1,a,n-1,0));
	return rmq(0,n_-1,a,b,0);
}
void opt2(int a,int b,ll t){
	if (a>b){
		inc(0,n_-1,0,b,0,t);
		inc(0,n_-1,a,n-1,0,t);
		return;
	}
	inc(0,n_-1,a,b,0,t); 
}
int main(){
	cin>>n;
	while (n_<n) n_<<=1;
	for (int i=0;i<n;i++){
		ll x;
		scanf ("%I64d",&x);
		inc(i,i,i,i,i+n_-1,x);
	}
	int Q;
	cin>>Q;
	gets(c);
	while (Q--){
		gets(c);
		istringstream ss(c);
		vector <int> tmp;
		int x;
		while (ss>>x) tmp.push_back(x); 
		if (tmp.size()==2) printf("%I64d\n",opt1(tmp[0],tmp[1]));
		else opt2(tmp[0],tmp[1],tmp[2]*1ll);
	}
}