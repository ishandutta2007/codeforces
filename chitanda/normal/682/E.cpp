//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))

const int maxn = 5010;

const double eps=1e-10;

struct Point{
	ll x,y;
	Point(ll x=0,ll y=0):x(x),y(y) { }
}p[maxn], ch[maxn], ansx, ansy, ansz;

Point operator - (Point A,Point B){return Point(A.x-B.x,A.y-B.y);}
Point operator + (Point A,Point B){return Point(A.x+B.x,A.y+B.y);}

bool operator < (const Point &A,const Point &B){
	return A.x==B.x?A.y<B.y:A.x<B.x;
}

int dcmp(double x){
	if (fabs(x)<eps) return 0; else return x<0?-1:1;
}

ll Cross(Point A,Point B) {return A.x*B.y-A.y*B.x;} /**/

int ConvexHull(Point* p,int n,Point* ch){
	sort(p+1,p+n+1); /*xy*/
	int m=0;
	for (int i=1;i<=n;i++){
		while (m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
		ch[m++]=p[i];
	}
	int k=m;
	for (int i=n-1;i;i--){
		while (m>k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
		ch[m++]=p[i];
	}
	if (n>1) m--;
	return m;
}

ll area(int i, int j, int k){
	return Cross(ch[j] - ch[i], ch[k] - ch[i]);
}

int n;
ll S, ans;

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> S;
	for(int i = 1; i <= n; ++i){
		cin >> p[i].x >> p[i].y;
		
	}
	n = ConvexHull(p, n, ch);
	for(int i = 1; i <= n; ++i){
		int k = i % n + 1;
		for(int j = i % n + 1; j != i; j = j % n + 1){
			while(area(i, j, k) - area(i, j, k % n + 1) <= 0) k = k % n + 1;
			if(area(i, j, k) > ans){
				ans = area(i, j, k);
				ansx = ch[i] + ch[j] - ch[k];
				ansy = ch[i] + ch[k] - ch[j];
				ansz = ch[j] + ch[k] - ch[i];
			}
		}
	}
	printf("%I64d %I64d\n%I64d %I64d\n%I64d %I64d\n", ansx.x, ansx.y, ansy.x, ansy.y, ansz.x, ansz.y);
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/