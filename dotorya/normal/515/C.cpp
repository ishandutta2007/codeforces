#include <stdio.h>
#include <vector>
using namespace std;
int cnt[4]; // 2,3,5,7
char d[16];
int table[10][4] = {{0,0,0,0},{0,0,0,0},{1,0,0,0},{1,1,0,0},{3,1,0,0},{3,1,1,0},{4,2,1,0},{4,2,1,1},{7,2,1,1},{7,4,1,1}};
vector <int> ANS;
int main() {
    int i, j, N;
    scanf("%d %s", &N, d);
    for(i = 0; i < N; i++) {
        for(j = 0; j <= 3; j++) {
            cnt[j] += table[d[i]-'0'][j];
        }
    }
    for(i = 1; i <= cnt[3]; i++) ANS.push_back(7);
    cnt[2] -= cnt[3], cnt[1] -= cnt[3]*2, cnt[0] -= cnt[3]*4;
    for(i = 1; i <= cnt[2]; i++) ANS.push_back(5);
    cnt[1] -= cnt[2], cnt[0] -= 3*cnt[2];
    for(i = 1; i <= cnt[1]; i++) ANS.push_back(3);
    cnt[0] -= cnt[1];
    for(i = 1; i <= cnt[0]; i++) ANS.push_back(2);
    for(i = 0; i < ANS.size(); i++) printf("%d", ANS[i]);
    return 0;
}