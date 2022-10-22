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
typedef pair<int,int> pii;
int n,k;
string s[3];
int vis[3][100004];
set <pair<int,pii> > q;
int main(){
	for (int i=0;i<3;i++)
		for (int j=0;j<100004;j++)
			vis[i][j]=1e9;
	cin>>n>>k;
	cin>>s[1]>>s[2];
	s[1]="*"+s[1];
	s[2]="*"+s[2];
	q.insert(make_pair(0,pii(1,1)));
	vis[1][1]=0;
	while (!q.empty()){
		pair<int,pii> x=*q.begin();
		int unn=x.first,u=x.second.first,v=x.second.second;
		q.erase(q.begin()); 
		if (unn>vis[u][v])
			continue;
		if (v+k>n){
			puts("YES");
			return 0;
		}
		if (vis[3-u][v+k]>vis[u][v]+1 && s[3-u][v+k]!='X' && vis[u][v]+1<v+k){
			vis[3-u][v+k]=vis[u][v]+1;
			q.insert(make_pair(vis[u][v]+1,pii(3-u,v+k)));
		}
		if (v+1>n){
			puts("YES");
			return 0;
		}
		if (vis[u][v+1]>vis[u][v] && s[u][v+1]!='X' && vis[u][v]+1<v+1){
			vis[u][v+1]=vis[u][v]+1;
			q.insert(make_pair(vis[u][v]+1,pii(u,v+1))); 
		}
		if (v-1>0 && vis[u][v-1]>vis[u][v] && s[u][v-1]!='X' && vis[u][v]+1<v-1){
			vis[u][v-1]=vis[u][v]+1;
			q.insert(make_pair(vis[u][v]+1,pii(u,v-1))); 
		}
	}
	puts("NO");
	return 0;
}