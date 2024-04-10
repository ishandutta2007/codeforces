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
int n;string s;bool rog=1;
int pr[200004],ans=0;
int vis[200004];
int gcd(int a,int b){
	if (a%b==0) return b;
	return gcd(b,a%b);
}
bool yes(int x){
	memset (vis,0,sizeof(vis));
	for (int i=1;i<=n;i++){
		int p=i%x;
		vis[p]^=s[i]-'0';
	}
	for (int i=0;i<x;i++) if (vis[i]!=0) return 0;
	return 1;
}
int main(){
	cin>>n>>s;
	s="0"+s;
	for (int i=1;i<=n;i++) if (s[i]=='1') rog=0;
	if (rog){
		cout<<n;return 0;
	}
	for (int i=1;i<n;i++)
		pr[gcd(n,i)]++;
	for (int i=1;i<n;i++) if(n%i==0)
		if (yes(i)) ans+=pr[i];
	cout<<ans;
}