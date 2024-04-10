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
int n,m,k;
bool vis[103][103][103];
int main(){
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int q=1;q<=k;q++) vis[i][j][q]=1;
	for (int i=1;i<=m;i++){
		int x;
		cin>>x;
		for (int j=1;j<=n;j++)
			for (int q=x+1;q<=k;q++)
				vis[j][i][q]=0;
	}
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		for (int j=1;j<=m;j++)
			for (int q=x+1;q<=k;q++)
				vis[i][j][q]=0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			int x;
			cin>>x;
			if (x==0) for (int q=1;q<=k;q++) vis[i][j][q]=0;
		}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int ans=0;
			for (int q=1;q<=k;q++)
				ans+=(vis[i][j][q]==1);
			cout<<ans<<" ";
		}
		puts("");
	}
}