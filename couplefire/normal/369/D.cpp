#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define ft first
#define sc second
 
typedef pair<int,int> pt;
 
const int N = 3000 + 50;
int n, k, p[N], d[N][N], sufP[N], sufO[N];
 
int main() {
 #ifdef gridnevvvit
 	freopen("input.txt", "rt", stdin);
 	freopen("output.txt", "wt", stdout);
 #endif
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> p[i];
	queue < pt > q;
  	for(int i = n - 1; i >= 0; i--) {
  	 	if (i + 1 != n) {
  	 	 	sufP[i] = sufP[i + 1];
  	 		sufO[i] = sufO[i + 1];
  	 	}
  	 	sufP[i] += (p[i] > 0);
  	 	sufO[i] += (p[i] == 100);
  	}
  	q.push(mp(0, 1));
	
	d[0][1] = 1;
 
	int ans = 1;
 
	while (!q.empty()) {
		pt cur = q.front(); q.pop();
 
		int A = cur.ft, B = cur.sc;
		                        
 
		if (A >= n || B >= n || d[A][B] > k)
			continue;	
		            
		if (p[A] > 0 && sufP[B] > 0 && d[B + 1][B + 2] == 0) {
			d[B + 1][B + 2] = d[A][B] + 1;
			ans ++;
			q.push(mp(B + 1, B + 2));
		}
 
		if (p[A] > 0 && sufO[B] == 0 && d[A][B + 1] == 0) {	
			d[A][B + 1] = d[A][B] + 1;
			ans ++;              
			q.push(mp(A, B + 1));
		}
 
		if (p[A] != 100 && sufP[B] > 0 && d[B][B + 1] == 0) {
			d[B][B + 1] = d[A][B] + 1;
			ans ++;
			q.push(mp(B, B + 1));
		}
	}
 
	cout << ans << endl;
}