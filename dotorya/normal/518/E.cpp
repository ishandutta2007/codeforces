#include <stdio.h>
#include <vector>
using namespace std;
vector <int> rem[100050];
int d[100050];
const int Q = -1234567891;
void input(int x, int y) {
    char t[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    scanf("%s", t);
    if(t[0] == '?') {
        d[x] = Q;
        rem[x%y].push_back(d[x]);
        return;
    }
    int chk = 1, st = 0;
    if(t[0] == '-') {
        chk = -1;
        st = 1;
    }
    for(int i = st; t[i] != 0; i++) {
        d[x] *= 10;
        d[x] += t[i]-'0';
    }
    d[x] *= chk;
    rem[x%y].push_back(d[x]);
    return;
}
int main() {
    int N, K, i, j, k, st, en, t1, t2;
    scanf("%d %d", &N, &K);
    for(i = 1; i <= N; i++) input(i, K);
    for(i = 0; i < K; i++) {
        if(rem[i].empty()) continue;
        st = -1;
        for(j = 0; j < rem[i].size(); j++) {
            if(j != 0) {
                if(rem[i][j] != Q && rem[i][j-1] != Q && rem[i][j] <= rem[i][j-1]) break;
            }
            if(st == -1 && rem[i][j] == Q) {
                st = j;
                continue;
            }
            if(st != -1 && rem[i][j] != Q) {
                t1 = j-st; // ? 
                if(st == 0) {
                    if(rem[i][j] <= (t1-1)/2) {
                        for(k = j-1; k >= st; k--) rem[i][k] = d[k*K+(i+K-1)%K+1] = rem[i][j]-j+k;
                    }
                    else {
                        for(k = j-1; k >= st; k--) rem[i][k] = d[k*K+(i+K-1)%K+1] = (t1+1)/2 + k - j;
                    }
                }
                else {
                    if(rem[i][j] <= rem[i][st-1] + t1) break;
                    if(rem[i][j] > (t1-1)/2) {
                        if(rem[i][st-1] < -t1/2) for(k = j-1; k >= st; k--) rem[i][k] = d[k*K+(i+K-1)%K+1] = (t1+1)/2 + k - j;
                        else for(k = st; k <= j-1; k++) rem[i][k] = d[k*K+(i+K-1)%K+1] = rem[i][st-1] + k - st + 1;
                    }
                    else for(k = j-1; k >= st; k--) rem[i][k] = d[k*K+(i+K-1)%K+1] = rem[i][j]-j+k;
                }
                st = -1;
            }   
        }
        if(j != rem[i].size()) break;
        if(st != -1) {
            t1 = j-st;
            if(st != 0) {
                if(rem[i][st-1] < -t1/2) for(k = j-1; k >= st; k--) rem[i][k] = d[k*K+(i+K-1)%K+1] = (t1+1)/2 + k - j;
                else for(k = st; k <= j-1; k++) rem[i][k] = d[k*K+(i+K-1)%K+1] = rem[i][st-1] + k - st + 1;
            }
            else {
                for(k = 0; k < j; k++) rem[i][k] = d[k*K+(i+K-1)%K+1] = -t1/2 + k;
            }
        }
    }
    if(i != K) printf("Incorrect sequence");
    else for(i = 1; i <= N; i++) printf("%d ", d[i]);
    return 0;
}