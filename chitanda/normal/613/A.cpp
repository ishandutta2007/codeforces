#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

int n, x, y, top;
struct node{
	int x, y;
	node() {}
	node(int x, int y):x(x), y(y) {}
}p[100100], o;
node operator - (node a, node b) { return node(a.x - b.x, a.y - b.y); }

ll cross(node a, node b){
	return (ll)a.x * b.y - (ll)a.y * b.x;
}

ll dot(node a, node b){
	return (ll)a.x * b.x + (ll)a.y * b.y;
}

double Length(node a){
	return sqrt(dot(a, a));
}

int main(){
	scanf("%d%d%d", &n, &o.x, &o.y);
	ll M = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &p[i].x, &p[i].y);
		M = max(M, dot(p[i] - o, p[i]- o));
	}
	double m = 1e18;
	p[n + 1] = p[1];
	for(int i = 1; i <= n; i++){
		m = min(m, Length(p[i] - o));
		if (dot(p[i + 1] - p[i], o - p[i]) >= 0 && dot(p[i] - p[i + 1], o - p[i + 1]) >= 0)
			m = min(m, abs(cross(p[i] - o, p[i + 1] - o)) / Length(p[i + 1] - p[i]));
	}
	printf("%.10lf\n", 3.141592653589793 * (M - m * m));
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