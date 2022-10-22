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
const int N=600010;
int n,m;
int s[N],ans[N];
void modify(int x,int v){
	while (x<=n){
		s[x]+=v;
		x=(x|(x-1))+1;
	}
}
int findsum(int x){
	int v=0;
	while (x>0){
		v+=s[x];
		x&=x-1;
	}
	return v;
}
int main(){
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;i++) s[i]=0;
	for (int i=1;i<=n;i++) modify(i,1);
	for (int i=1;i<=n;i++) ans[i]=0;
	while (m--){
		int from,to,win;
		scanf ("%d%d%d",&from,&to,&win);
		int dec=findsum(from-1);
		int add=findsum(to);
		while (add>dec){
			int ll=from,rr=to;
			while (ll<rr){
				int mid=(ll+rr)>>1;
				if (findsum(mid)==dec) ll=mid+1;
				else rr=mid;
			}
			ans[ll]=win;
			modify(ll,-1);
			add--;
		}
		ans[win]=0;
		modify(win,1);
	}
	for (int i=1;i<n;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
}