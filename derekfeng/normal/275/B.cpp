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
int n,m;
char c[53][53];
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++){
			cin>>c[i][j];
		}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) if (c[i][j]=='B'){
			int dist[53][53];
			for (int i=0;i<n;i++)
				for (int j=0;j<m;j++) dist[i][j]=1e9;
			queue <int> qu,qv;
			dist[i][j]=0;
			qu.push(i),qv.push(j);
			while (!qu.empty()){
				int ux=qu.front(),vy=qv.front();
				qu.pop(),qv.pop();
				for (int i1=ux-1;i1>=0 && c[i1][vy]=='B';i1--)
					if (dist[i1][vy]>dist[ux][vy]){
						qu.push(i1),qv.push(vy);
						dist[i1][vy]=dist[ux][vy]+1;
						qu.push(i1),qv.push(vy);  
					}
					else break;
				for (int i1=ux+1;i1<n && c[i1][vy]=='B';i1++)
					if (dist[i1][vy]>dist[ux][vy]){
						qu.push(i1),qv.push(vy);
						dist[i1][vy]=dist[ux][vy]+1;
						qu.push(i1),qv.push(vy);  
					}
					else break;
				for (int j1=vy-1;j1>=0 && c[ux][j1]=='B';j1--)
					if (dist[ux][j1]>dist[ux][vy]){
						qu.push(ux),qv.push(j1);
						dist[ux][j1]=dist[ux][vy]+1;
						qu.push(ux),qv.push(j1);    
					}
					else break;
				for (int j1=vy+1;j1<m && c[ux][j1]=='B';j1++)
					if (dist[ux][j1]>dist[ux][vy]){
						qu.push(ux),qv.push(j1);
						dist[ux][j1]=dist[ux][vy]+1;
						qu.push(ux),qv.push(j1);    
					}
					else break;
			}
			for (int i=0;i<n;i++)
				for (int j=0;j<m;j++)
					if (c[i][j]=='B' && (dist[i][j]==1e9 || dist[i][j]>=3)){
						cout<<"NO";
						return 0;
					}
	}
	cout<<"YES";
	return 0;
}