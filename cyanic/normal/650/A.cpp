/*
n

.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> point;

map<int,int> X, Y;
map<point,int> P;
int n, x, y; LL ans; 
point p;

int main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d%d", &x, &y);
		p = make_pair(x, y);
		X[x]++; Y[y]++; P[p]++;
	}
	for (map<int,int>::iterator it=X.begin(); it!=X.end(); it++)
		ans += 1LL*it->second*(it->second-1);
	for (map<int,int>::iterator it=Y.begin(); it!=Y.end(); it++)
		ans += 1LL*it->second*(it->second-1);
	for (map<point,int>::iterator it=P.begin(); it!=P.end(); it++)
		ans -= 1LL*it->second*(it->second-1);
	printf("%I64d\n", ans/2);
	return 0;
}