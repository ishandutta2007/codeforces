//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef set <int>::iterator siit;
typedef set <ll>::iterator slit;

const int IT_MAX = 32768;
const int MOD = 1000000007;

set <pic> S;
char Home[30];
char Away[30];
int chk[2][100];
int main() {
    int N, i, t1, t3;
    char t2[2], t4[2];
    scanf("%s %s", Home, Away);
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d %s %d %s", &t1, t2, &t3, t4);
        set <pic>::iterator it = S.find(make_pair(t3, t2[0]));
        if(it == S.end() && t4[0] == 'y') S.insert(make_pair(t3, t2[0]));
        else {
            if((t2[0] == 'a' && chk[0][t3] == 1) || (t2[0] == 'h' && chk[1][t3] == 1)) continue;
            int t5;
            if(t2[0] == 'a') {
                printf("%s ", Away);
                t5 = 0;
            }
            else {
                t5 = 1;
                printf("%s ", Home);
            }
            printf("%d %d\n", t3, t1);
            S.erase(make_pair(t3, t2[0]));
            chk[t5][t3]++;
        }
    }

    return 0;
}

//*/