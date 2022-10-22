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
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define T (1<<17)
int tree[2*T];
void update(int L,int R,int val,int id=1,int low=0,int high=T){
	if (L<=low && R>=high){
		tree[id]=val;
		return;
	}
	int mid=(low+high)/2;
	if (L<mid) update(L,R,val,2*id,low,mid);
	if (R>mid) update(L,R,val,2*id+1,mid,high);
}
int get(int x){
	x+=T;
	int ans=0;
	while (1){
		ans=max(ans,tree[x]);
		x/=2;
		if (x==0) return ans;
	}
}
int a[100010],b[100010],diff[100010];
int main(void){
	int N,Q,i;
	cin>>N>>Q;
	REP(i,N) scanf("%d",&a[i]);
	REP(i,N) scanf("%d",&b[i]);
	REP(i,Q){
		int t;
		scanf ("%d",&t);
		if (t==1){
			int x,y,k;
			scanf ("%d%d%d",&x,&y,&k);
			update(y-1,y-1+k,i+1);
			diff[i+1]=x-y;
		}else{
			int x;
			scanf ("%d",&x);
			x--;
			int tmp=get(x);
			if(tmp==0){
				printf("%d\n",b[x]);
			}else{
				printf("%d\n",a[x+diff[tmp]]);
			}
		}
	}
	return 0;
}