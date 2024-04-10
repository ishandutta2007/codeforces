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
vector <int> conn[505];
int inc[505];
int mn[505];
bool dchk[505];
vector <int> Vu;
int main(){
	int N,M,i,j;
	scanf ("%d%d",&N,&M);
	for (i=1;i<=M;i++){
		int t1,t2;
		scanf ("%d%d",&t1,&t2);
		conn[t1].push_back(t2);
	}
	for (i=1;i<=N;i++){
		memset (inc,0,sizeof(inc));
		for (int j=1;j<=N;j++) for (auto it:conn[j]) inc[it]++;
		mn[i-1]=0;
		mn[i]=1;
		Vu.clear();
		memset (dchk,0,sizeof(dchk));
		for (j=1;j<=N;j++){
			if (inc[j]<=mn[j]){
				dchk[j]=true;
				Vu.push_back(j);
			}
		}
		for (j=0;j<Vu.size();j++){
			for (auto it:conn[Vu[j]]){
				inc[it]--;
				if (inc[it]<=mn[it] && !dchk[it]){
					dchk[it]=true;
					Vu.push_back(it);
				}
			}
		}
		if (Vu.size()==N) return !printf("YES\n");
	}
	return !printf("NO\n");
}