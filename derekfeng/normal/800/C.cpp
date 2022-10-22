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
int K,n,w[201000],cnt,phi;
int chk[201000],D[201000],Path[201000],Res[201000],cc;
vector <int> G[201000];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int Pow(int a,int b){
	int r=1;
	while (b){
		if (b&1) r=1ll*r*a%n;
		a=1ll*a*a%n,b>>=1;
	}
	return r;
}
int Get(int a,int b){
	int g=gcd(a,b);
	a/=g,b/=g;
	return 1ll*b*Pow(a,phi-1)%n; 
}
int main(){
	int i,a,j;
	scanf ("%d%d",&K,&n);
	phi=n;
	int tn=n;
	for (i=2;i<=n;i++){
		if (tn%i==0){
			phi=phi/i*(i-1);
			while (tn%i==0) tn/=i;
		}
	}
	for (i=0;i<K;i++){
		scanf ("%d",&a);
		chk[a]=1;
	}
	for (i=0;i<n;i++){
		if (chk[i]) continue;
		G[gcd(i,n)].push_back(i);
	}
	for (i=1;i<=n;i++){
		if (n%i) continue;
		D[i]+=int(G[i].size());
		for (j=i+i;j<=n;j+=i){
			if (n%j) continue;
			if (D[j]<=D[i]){
				D[j]=D[i];
				Path[j]=i;
			}
		}
	}
	a=n;
	while (1){
		for (i=0;i<G[a].size();i++) w[cnt++]=G[a][i];
		if (a==1) break;
		a=Path[a];
	}
	printf("%d\n",cnt);
	printf("%d ",w[cnt-1]);
	for (i=cnt-1;i>0;i--){
		printf("%d ",Get(w[i],w[i-1]));
	}
}