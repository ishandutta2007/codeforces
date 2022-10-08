#include <stdio.h>
#include <algorithm>
using namespace std;
char d[505][505];
int N, M;
class data {
public:
    int x, y;
    data() {
        data(0,0);
    }
    data(int a, int b) {
        x = a, y = b;
    }
    bool isValid() {
        if(x <= N && x >= 1 && y <= M && y >= 1 && d[x][y] == '.') return true;
        else return false;
    }
    data plus(data k) {
        return data(x+k.x, y+k.y);
    }
};
data Q[250050];
data P[4] = {data(1,0), data(-1,0), data(0,1), data(0,-1)};
bool Q_chk[505][505];
int main() {
    int i, j, t1, t2;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++) scanf("%s", &d[i][1]);
    scanf("%d %d", &t1, &t2);
    data S = data(t1,t2);
    scanf("%d %d", &t1, &t2);
    data E = data(t1, t2);

    // BFS
    int st = 1, en = 2;
    Q[1] = S;
    Q_chk[S.x][S.y] = true;
    while(st < en) {
        data tmp = Q[st];
        for(i = 0; i < 4; i++) {
            data tmp2 = tmp.plus(P[i]);
            if(!tmp2.isValid()) continue;
            if(Q_chk[tmp2.x][tmp2.y]) continue;
            Q[en++] = tmp2;
            Q_chk[tmp2.x][tmp2.y] = true;
        }
        st++;
    }

    // Get answer
    if(S.x == E.x && S.y == E.y) {
        int chk = 0;
        for(i = 0; i < 4; i++) {
            data tmp = S.plus(P[i]);
            if(tmp.isValid()) chk++;
        }
        if(chk != 0) printf("YES");
        else printf("NO");
        return 0;
    }
    for(i = 0; i < 4; i++) {
        data tmp = S.plus(P[i]);
        if(tmp.x == E.x && tmp.y == E.y) break;
    }
    if(i != 4) {
        if(d[E.x][E.y] == 'X') {
            printf("YES");
            return 0;
        }
        int chk = 0;
        for(i = 0; i < 4; i++) {
            data tmp = E.plus(P[i]);
            if(tmp.isValid()) chk++;
        }
        if(chk != 0) printf("YES");
        else printf("NO");
        return 0;
    }
    if(d[E.x][E.y] == '.') {
        if(Q_chk[E.x][E.y]) {
            int chk = 0;
            for(i = 0; i < 4; i++) {
                data tmp = E.plus(P[i]);
                if(!tmp.isValid()) continue;
                chk++;
            }
            if(chk >= 2) printf("YES");
            else printf("NO");
            return 0;
        }
        printf("NO");
        return 0;
    }
    int chk = 0;
    for(i = 0; i < 4; i++) {
        data tmp = E.plus(P[i]);
        if(!tmp.isValid()) continue;
        if(Q_chk[tmp.x][tmp.y]) chk++;
    }
    if(chk != 0) printf("YES");
    else printf("NO");
    return 0;
}