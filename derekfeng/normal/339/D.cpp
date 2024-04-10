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
const int N=1<<18;
int n,q;
int a[N];
void update(int id,int t){
	a[id]=t;
	int x=0;
	id=(id-1)/2;
	while(1){
		if (x%2==0)a[id]=a[id*2+1]|a[id*2+2];
		else a[id]=a[id*2+1]^a[id*2+2];
		if (id==0) return;
		id=(id-1)/2;
		x++;
	}
}
int main(){
	cin>>n>>q;
	n=1<<n;
	for (int i=0;i<n;i++){
		int x;
		scanf ("%d",&x);
		update(n+i-1,x);
	}
	while (q--){
		int x,y;
		scanf ("%d%d",&x,&y);
		update(n+x-2,y);
		printf("%d\n",a[0]);
	}
}