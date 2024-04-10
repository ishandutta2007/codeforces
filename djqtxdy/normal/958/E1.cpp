#include <bits/stdc++.h>
using namespace std;
int n, m, t[15];
struct Point {  
	double x,y;  
} a[15], b[15];
double mult(Point a, Point b, Point c) {  
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);  
}  
bool intersect(Point aa, Point bb, Point cc, Point dd) {  
    if ( max(aa.x, bb.x)<min(cc.x, dd.x) )  
        return false;  
    if ( max(cc.x, dd.x)<min(aa.x, bb.x) )  
        return false;  
    if ( max(aa.y, bb.y)<min(cc.y, dd.y) )  
        return false;  
    if ( max(cc.y, dd.y)<min(aa.y, bb.y) )  
        return false;  
    if(mult(cc,bb,aa) * mult(dd,bb,aa) <= 0  
       && mult(aa,dd,cc) * mult(bb,dd,cc) <= 0)  
        return true;  
    return false;  
}
int main() {
	scanf("%d%d", &n, &m);
	if (n != m) {
		puts("No");
		return 0;
	}
	for (int i = 0; i < n; i++)
		scanf("%lf%lf", &a[i].x, &a[i].y);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf", &b[i].x, &b[i].y);
	for (int i = 0; i < n; i++)
		t[i] = i;
	do {
		bool flag = true;
		for (int i = 0; i < n && flag; i++)
			for (int j = i + 1; j < n && flag; j++) {
				if (intersect(a[i], b[t[i]], a[j], b[t[j]]))
					flag = false;
			}
		if (flag) {
			puts("Yes");
			return 0;
		}
	} while (next_permutation(t, t + n));
	puts("No");
	return 0;
}