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
bool vis[1000005];
int havep[1000005];
int a,b,k;
void summon_prime(){
	memset (vis,0,sizeof(vis));
	vis[1]=1;
	for (int i=2;i<=1000005;i++)
		if (!vis[i]){
			int l=i;
			while (l<=1000005){
				l+=i;
				if (l>1000005) break;
				vis[l]=1;
			}
		}
	int pr=0;
	for (int i=1;i<=1000005;i++){
		if (!vis[i]) pr++;
		havep[i]=pr;
	}
}
bool check(int mid){
	for (int i=a;i+mid-1<=b;i++){
		int amid=i+mid-1;
		int p=havep[amid]-havep[i-1];
		if (p<k) return false;
	}
	return true;
}
int main(){
	summon_prime();
	cin>>a>>b>>k;
	int l=0,r=b-a+1,mid;
	while (r-l>1){
		mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid;
	}
	if (!check(r)) cout<<"-1";
	else cout<<r;
	return 0;
}