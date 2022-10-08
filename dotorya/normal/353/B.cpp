#include <stdio.h>
#include <vector>
using namespace std;

vector <int> chk[105];
vector <int> exactly1;
vector <int> left;
int ANS[205];

int main() {
    int N, i, j, t, CNT1 = 0, CNT2 = 0, ANS_CNT1 = 0, ANS_CNT2 = 0;

    scanf("%d", &N);
    for(i = 1; i <= 2*N; i++) {
        scanf("%d", &t);
        chk[t].push_back(i);
    }

    for(i = 10; i <= 99; i++) {
        if(chk[i].size() == 0) continue;
        if(chk[i].size() == 1) {
            exactly1.push_back(chk[i][0]);
            chk[i].clear();
            CNT1++;
        }
        else if(chk[i].size() >= 2) {
            ANS[chk[i].back()] = 1;
            chk[i].pop_back();
            ANS[chk[i].back()] = 2;
            chk[i].pop_back();
            while(!chk[i].empty()) {
                left.push_back(chk[i].back());
                chk[i].pop_back();
            }
            CNT2++;
            ANS_CNT1++;
            ANS_CNT2++;
        }
    }

    printf("%d\n", (CNT2+CNT1/2)*(CNT1+CNT2-CNT1/2));

    for(i = 0; i < exactly1.size(); i++) {
        if(i%2 == 0) {
            ANS_CNT1++;
            ANS[exactly1[i]] = 1;
        }
        else {
            ANS_CNT2++;
            ANS[exactly1[i]] = 2;
        }
    }
    while(ANS_CNT1 != N) {
        ANS[left.back()] = 1;
        ANS_CNT1++;
        left.pop_back();
    }
    while(!left.empty()) {
        ANS[left.back()] = 2;
        left.pop_back();
    }
    for(i = 1; i <= 2*N; i++) printf("%d ", ANS[i]);
    return 0;
}