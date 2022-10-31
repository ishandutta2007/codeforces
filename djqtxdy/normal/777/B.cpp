#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
//orz mqy
int main(){
	int n;
	string x,y;
	cin>>n;
	cin>>x>>y;
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	int p=-1;
	int i=0;
	for (i=0;i<n;i++){
		p++;
		if (p==n) break;
		while (p!=n && y[p]<x[i]) p++;
		if (p==n) break;
	}
	printf("%d\n",n-i);
	p=-1;
	for (i=0;i<n;i++){
		p++;
		if (p==n) break;
		while (p!=n && y[p]<=x[i]) p++;
		if (p==n) break;
	}
	printf("%d\n",i);
	return 0;
}