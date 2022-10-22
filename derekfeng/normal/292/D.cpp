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
struct DSU{
	int f[503],c=0;
	int Find(int x){return f[x]?f[x]=Find(f[x]):x;}	
	void Link(int x,int y){x=Find(x),y=Find(y); if (x!=y) f[x]=y,c++;}
}L[10004],R[10004],ans;
int n,m,x[10003],y[10003],q;
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++) cin>>x[i]>>y[i];
	for (int i=1;i<=m;i++) L[i]=L[i-1],L[i].Link(x[i],y[i]);
	for (int i=m;i>=1;i--) R[i]=R[i+1],R[i].Link(x[i],y[i]);
	cin>>q;
	while (q--){
		int l,r;
		cin>>l>>r;
		ans=L[l-1];
		for (int i=1;i<=n;i++) if (R[r+1].f[i]) ans.Link(i,R[r+1].f[i]); 
		cout<<n-ans.c<<"\n";
	}
}