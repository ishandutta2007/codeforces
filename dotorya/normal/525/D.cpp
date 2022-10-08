#include <stdio.h>
int N, M;
char d[2050][2050];
class Point {
public:
    Point() {
        Point(0,0);
    }
    Point(int a, int b) {
        x = a, y = b;
    }
    int x, y;
    bool isValid() {
        if(x > 0 && x < N && y > 0 && y < M) return true;
        else return false;
    }
} Q[4000050];
bool Q_chk[2050][2050];

bool BFSchk(Point k) {
    int cnt = 0, i, j;
    int x = k.x, y = k.y;
    for(i = x; i <= x+1; i++) for(j = y; j <= y+1; j++) cnt += (d[i][j] == '.')?1:0;
    if(cnt == 3) return true;
    else return false;
}

void update(Point k) {
    int i, j;
    for(i = k.x; i <= k.x+1; i++) for(j = k.y; j <= k.y+1; j++) d[i][j] = '.';
    return;
}
int main() {
    int i, j;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++) scanf("%s", &d[i][1]);

    //BFS
    int st = 1, en = 1;
    for(i = 1; i < N; i++) for(j = 1; j < M; j++) {
        if(BFSchk(Point(i, j))) {
            Q[en++] = Point(i, j);
            Q_chk[i][j] = true;
        }
    }
    
    while(st < en) {
        Point tmp = Q[st];
        update(tmp);
        for(i = tmp.x-1; i <= tmp.x+1; i++) {
            for(j = tmp.y-1; j <= tmp.y+1; j++) {
                Point tmp2 = Point(i, j);
                if(!tmp2.isValid()) continue;
                if(BFSchk(tmp2) && !Q_chk[i][j]) {
                    Q[en++] = tmp2;
                    Q_chk[i][j] = true;
                }
            }
        }
        st++;
    }

    //Print ANS
    for(i = 1; i <= N; i++) {
        for(j = 1; j <= M; j++) printf("%c", d[i][j]);
        printf("\n");
    }
    return 0;
}