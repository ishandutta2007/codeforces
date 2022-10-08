#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
bool prime_chk[100050];
vector <int> prime_list;
int d[105];
int d_prime[105][300];
vector <int> d_prime_list;
int conn[300][105][105];
int flow_chk[105];
int d2[105][2];
const int INF = 123456789;
int N;
int dPrimeChk_before_sort(int x) {
    int i;
    for(i = 0; i < d_prime_list.size(); i++) {
        if(x == d_prime_list[i]) return 1;
    }
    return -1;
}
int dPrimeChk(int x) {
    int st = 0, en = d_prime_list.size()-1, mi;
    while(st <= en) {
        mi = (st+en)/2;
        if(x == d_prime_list[mi]) return mi;
        if(x > d_prime_list[mi]) st = mi+1;
        else en = mi-1;
    }
    return -1;
}
bool GetFlow(int node, int chk) {
    flow_chk[node] = chk;
    if(node == N+1) return true;
    for(int i = 0; i <= N+1; i++) {
        if(flow_chk[i] == chk) continue;
        if(conn[chk][node][i] == 0) continue;
        if(GetFlow(i, chk)) {
            conn[chk][node][i]--;
            conn[chk][i][node]++;
            return true;
        }
    }
    return false;
}
int main() {
    int i, j, M, cnt, t, t2;
    for(i = 2; i <= 100000; i++) {
        if(prime_chk[i]) continue;
        prime_list.push_back(i);
        for(j = 2*i; j <= 100000; j+=i) prime_chk[j] = true;
    }
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++) {
        scanf("%d", &d[i]);
        t = d[i];
        for(j = 0; prime_list[j]*prime_list[j] <= t; j++) {
            cnt = 0;
            while(t%prime_list[j] == 0) {
                t /= prime_list[j];
                cnt++;
            }
            if(cnt == 0) continue;
            t2 = dPrimeChk_before_sort(prime_list[j]);
            if(t2 == -1) d_prime_list.push_back(prime_list[j]);
        }
        if(t == 1) continue;
        t2 = dPrimeChk_before_sort(t);
        if(t2 == -1) d_prime_list.push_back(t);
    }
    std::sort(d_prime_list.begin(), d_prime_list.end());
    for(i = 1; i <= N; i++) {
        t = d[i];
        for(j = 0; prime_list[j]*prime_list[j] <= t; j++) {
            cnt = 0;
            while(t%prime_list[j] == 0) {
                t /= prime_list[j];
                cnt++;
            }
            if(cnt == 0) continue;
            t2 = dPrimeChk(prime_list[j]);
            d_prime[i][t2] = cnt;
        }
        if(t == 1) continue;
        t2 = dPrimeChk(t);
        d_prime[i][t2] = 1;
    }
    for(i = 1; i <= M; i++) {
        scanf("%d %d", &t, &t2);
        if(t%2 == 1) swap(t, t2);
        d2[i][0] = t, d2[i][1] = t2;
        for(j = 0; j < d_prime_list.size(); j++) {
            conn[j][t][t2] = INF;
            conn[j][0][t] = d_prime[t][j];
            conn[j][t2][N+1] = d_prime[t2][j];
        }
    }
    int ANS = 0;
    for(i = 0; i <= N+1; i++) flow_chk[i] = -1;
    for(i = 0; i < d_prime_list.size(); i++) {
        for(j = 0;;j++) {
            if(!GetFlow(0, i)) break;
            for(t = 0; t <= N+1; t++) flow_chk[t] = -1;
        }
        ANS += j;
    }
    printf("%d", ANS);
    return 0;
}