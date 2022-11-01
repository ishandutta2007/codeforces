#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <list>
#include <stack>
#include <utility> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N =1e5+6; 
const int M=100010;
const int maxn=1001;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pi acos(-1.0)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int dx[] = {-1, 0, 0, 1}; 
int dy[] = {0, -1, 1, 0}; 
int sx, sy, tx, ty;

ll n, m, k;
double mnx, mny, mxx, mxy;
double stx, sty, enx, eny;
int rx[N], ry[N], vx[N], vy[N];
int ok(double mid) {

	for (int i = 0; i<n; i++)
	{
		double x = rx[i] + vx[i] * mid;
		double y = ry[i] + vy[i] * mid;
		if (x >= mnx&&x <= mxx&&y >= mny&&y <= mxy) {

		}
		else {
			if (vx[i]>0) {
				if (x>mxx)return 1;
				if (x<mnx)return 0;
			}
			if (vx[i]<0) {
				if (x>mxx)return 0;
				if (x<mnx)return 1;
			}
			if (vy[i]>0) {
				if (y>mxy)return 1;
				if (y<mny)return 0;
			}
			if (vy[i]<0) {
				if (y>mxy)return 0;
				if (y<mny)return 1;
			}


		}
	}
	return 2;

}
int main()
{
//	in;
	cin >> n;
	cin >> stx >> sty >> enx >> eny;
	mnx = min(stx, enx);
	mny = min(sty, eny);
	mxx = max(stx, enx);
	mxy = max(sty, eny);
	bool ans = 1;
	for (int i = 0; i<n; i++) {
		cin >> rx[i] >> ry[i] >> vx[i] >> vy[i];
		if (rx[i]>=mxx&&vx[i] >= 0) {
			ans = 0;
		}
		if (rx[i]<=mnx&&vx[i] <= 0) {
			ans = 0;
		}

		if (ry[i]>=mxy&&vy[i] >= 0) {
			ans = 0;
		}
		if (ry[i]<=mny&&vy[i] <= 0) {
			ans = 0;
		}
	}
	if (!ans) {
		cout << -1;
		return 0;
	}
	double l = 0, r = 1e9, answer = -1;
	while (abs(r-l)>1e-10){
	double mid = (l + r) / 2;
		int c = ok(mid);
		if (c == 2) {
			r = mid;
			answer = mid;
		}
		else if (c == 1) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout <<fixed<<setprecision(9)<< answer << endl;
}