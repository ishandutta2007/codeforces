#include <stdio.h>
#include <vector>
using namespace std;
int N;
class Point {
public:
	int x, y;
	Point() {
		Point(0, 0);
	}
	Point(int a, int b) {
		x = a, y = b;
	}
	Point plus(Point k) {
		return Point(x+k.x, y+k.y);
	}
	bool isValid() {
		if(x <= N && x >= 1 && y <= N && y >= 1) {
			return true;
		}
		else return false;
	}
};
vector <Point> P;
char d[55][55];
char ans[105][105];
char d2[55][55];
int main() {
	int i, j, k;
	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%s", &d[i][1]);
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= N; j++) {
			if(d[i][j] == 'o') {
				P.push_back(Point(i, j));
			}
		}
	}
	for(i = 1; i <= N; i++) for(j = 1; j <= N; j++) d2[i][j] = '.';
	for(i = 1; i <= 2*N-1; i++) for(j = 1; j <= 2*N-1; j++) ans[i][j] = '.';
	ans[N][N] = 'o';

	for(i = -N+1; i <= N-1; i++) {
		for(j = -N+1; j <= N-1; j++) {
			if(i == 0 && j == 0) continue;
			for(k = 0; k < P.size(); k++) {
				Point t = Point(i,j);
				Point t2 = P[k].plus(t);
				if(!(t2).isValid()) continue;
				if(d[t2.x][t2.y] == '.') break;
			}
			if(k == P.size()) {
				ans[N+i][N+j]='x';
				for(k = 0; k < P.size(); k++) {
					Point t2 = P[k].plus(Point(i, j));
					if(!t2.isValid()) continue;
					d2[t2.x][t2.y] = 'x';
				}
			}
		}
	}

	for(i = 1; i <= N; i++) {
		for(j = 1; j <= N; j++) {
			if(d[i][j] == 'x' && d2[i][j] == '.') break;
		}
		if(j != N+1) break;
	}
	if(i != N+1) {
		printf("NO");
		return 0;
	}
	
	printf("YES\n");
	for(i = 1; i <= 2*N-1; i++) {
		for(j = 1; j <= 2*N-1; j++) printf("%c", ans[i][j]);
		printf("\n");
	}
	return 0;
}