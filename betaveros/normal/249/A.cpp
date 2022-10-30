#include <cstdio>
#include <cmath>
using std::scanf;
using std::printf;
using std::sqrt;

#define y1 yy1
#define y2r yy2r

int xb, yb, yw, y1, y2, xrf, r;


double xw;
bool success;

void aim(){
	int yr = yw - r;
	int y1ref = 2*yr - y1;

	int y2ref = 2*yr - y2;
	
	//printf("y1: %d, y2: %d, yr: %d, y1r: %d, y2r: %d\n", y1, y2, yr, y1ref, y2ref);
	double yAim = y1ref - r;
	double ydiff = yAim - yb;
	double xbd = xb;
	double c = sqrt(ydiff*ydiff + xbd*xbd) / xbd;
	double projectedR = r * c;
	if (projectedR + r < y1ref - y2ref){
	//if (true){
		xw = xb * (yAim - yr) / (yAim - yb);
		success = true;
	} else success = false;
}


void readInput(){
	//cin >> y1 >> y2 >> yw >> xb >> yb >> r;
	scanf("%d %d %d %d %d %d", &y1, &y2, &yw, &xb, &yb, &r);
}

int main(){
	readInput();
	aim();
	if (success) {
		printf("%.15f\n", xw);
	}
	else printf("-1\n");
}