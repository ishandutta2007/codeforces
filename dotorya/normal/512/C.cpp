#include <stdio.h>
#include <vector>
using namespace std;
vector <int> V_ODD;
vector <int> V_EVEN;
vector <int> R;
vector <int> ANS[250];
int d[250];
int conn[250][250];
int ans_conn[250][250];
bool prime_chk[20050];
int t_chk[20050];
int N;
int ans_chk[250];
void PrimeCheck() {
    int i, j;
    for(i = 2; i <= 20000; i++) {
        if(prime_chk[i]) continue;
        for(j = 2*i; j <= 20000; j += i) prime_chk[j] = true;
    }
    return;
}
void GetConn() {
    int i, j;
    for(i = 1; i <= N; i++) {
        for(j = i+1; j <= N; j++) {
            if(prime_chk[d[i]+d[j]]) continue;
            if(d[i] % 2 == 0) conn[i][j] = 1;
            else conn[j][i] = 1;
        }
    }
    return;
}
bool GetFlow(int nod, int chk) {
    int i, j;
    t_chk[nod] = chk;
    if(nod == N+1) {
        R.push_back(nod);
        return true;
    }
    for(i = 0; i <= N+1; i++) {
        if(t_chk[i] == chk) continue;
        if(conn[nod][i] == 0) continue;
        if(GetFlow(i, chk)) {
            conn[nod][i]--;
            conn[i][nod]++;
            R.push_back(nod);
            return true;
        }
    }
    return false;
}
int main() {
    int i, j, t, t1, t2;
    PrimeCheck();
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d", &t);
        d[i] = t;
        if(d[i] % 2 == 0) {
            V_EVEN.push_back(i);
            conn[0][i] = 2;
        }
        else {
            V_ODD.push_back(i);
            conn[i][N+1] = 2;
        }
    }
    GetConn();
    for(i = 1; i <= N; i++) {
        if(!GetFlow(0, i)) break;
        while(R.size() >= 2) {
            t1 = R.back();
            t2 = R[R.size()-2];
            if(ans_conn[t2][t1] >= 1) ans_conn[t2][t1]--;
            else ans_conn[t1][t2]++;
            R.pop_back();
        }
        R.clear();
    }
    if(i != N+1) {
        printf("Impossible");
        return 0;
    }
    int cnt = 0;
    for(i = 0; i < V_EVEN.size(); i++) {
        if(ans_chk[V_EVEN[i]] == 1) continue;
        t1 = V_EVEN[i];
        cnt++;
        do {
            for(j = 1; j <= N; j++) {
                if(ans_conn[t1][j] == 1 || ans_conn[j][t1] == 1) break;
            }
            if(j == N+1) {
                printf("ERR");
                return 0;
            }
            ANS[cnt].push_back(t1);
            ans_chk[t1] = 1;
            ans_conn[t1][j] = ans_conn[j][t1] = 0;
            t1 = j;
        } while(t1 != V_EVEN[i]);
    }
    printf("%d\n", cnt);
    for(i = 1; i <= cnt; i++) {
        printf("%d ", ANS[i].size());
        for(j = 0; j < ANS[i].size(); j++) printf("%d ", ANS[i][j]);
        printf("\n");
    }
    return 0;
}