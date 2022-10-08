#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef pair<char, char> pcc;

char C[10] = {'B', 'Y', 'W', 'G', 'R', '1', '2', '3', '4', '5'};
char T[3];

set <pcc> INP;
vector <int> chk;

int val[105];

int pow2[15];

int count1(int x) {
    int ans;
    for(ans = 0; x != 0; ans++) {
        int su = x&-x;
        x -= su;
    }
    return ans;
}
int main() {
    int N, i, j, k;
    pow2[0] = 1;
    for(i = 1; i < 10; i++) pow2[i] = pow2[i-1]*2;

    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%s", T);
        pcc tmp = make_pair(T[0], T[1]);
        INP.insert(tmp);
    }

    int ANS = 10;
    for(i = 0; i < (1<<10); i++) {
        for(j = 0; j < INP.size(); j++) val[j] = 0;
        int t = i;
        for(j = 0; j < 10; j++) {
            if(t%2 == 1) {
                set <pcc>::iterator tmp = INP.begin();
                if(j < 5) {
                    for(k = 0; k < INP.size(); k++) {
                        if(tmp->first == C[j]) val[k] += pow2[j];
                        tmp++;
                    }
                }
                else {
                    for(k = 0; k < INP.size(); k++) {
                        if(tmp->second == C[j]) val[k] += pow2[j];
                        tmp++;
                    }
                }
            }
            t /= 2;
        }
        sort(val, val+INP.size());
        for(j = 0; j < INP.size()-1; j++) if(val[j] == val[j+1]) break;
        if(j == INP.size()-1) ANS = min(ANS, count1(i));
    }
    printf("%d", ANS);
    return 0;
}