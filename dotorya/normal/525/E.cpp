//*
#include <stdio.h>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
typedef long long ll;
using namespace std;
struct data {
    data() {
        data(0,0);
    }
    data(ll a, ll b) {
        num = a, cnt = b;
    }
    ll num, cnt;
};
vector <ll> V1[100][100];
vector <ll> V2[100][100];
vector <data> V_t1[100];
vector <data> V_t2[100];
vector <data> M[100];
ll fact[100];
ll d[1000];
int main() {
    int N, K, i, j, k;
    ll S, ANS = 0;
    fact[0] = 1;
    for(i = 1; i <= 18; i++) fact[i] = fact[i-1]*i;
    scanf("%d %d %lld", &N, &K, &S);
    for(i = 1; i <= N; i++) scanf("%lld", &d[i]);
    if(N == 1) {
        if(S == d[1]) ANS++;
        if(K == 1 && d[1] <= 18) {
            if(S == fact[d[1]]) ANS++;
        }
        printf("%lld", ANS);
        return 0;
    }
    ////// For 1~N/2
    V1[1][0].push_back(0);
    V1[1][0].push_back(d[1]);
    if(d[1] <= 18) V1[1][1].push_back(fact[d[1]]);
    for(i = 2; i <= N/2; i++) {
        for(j = 0; j < i; j++) {
            for(k = 0; k < V1[i-1][j].size(); k++) V1[i][j].push_back(V1[i-1][j][k]);
            for(k = 0; k < V1[i-1][j].size(); k++) V1[i][j].push_back(V1[i-1][j][k]+d[i]);
            if(d[i] <= 18) for(k = 0; k < V1[i-1][j].size(); k++) V1[i][j+1].push_back(V1[i-1][j][k]+fact[d[i]]);
        }
    }
    for(i = 0; i <= N/2; i++) {
        if(V1[N/2][i].size() == 0) continue;
        sort(V1[N/2][i].begin(), V1[N/2][i].end());
        V_t1[i].push_back(data(V1[N/2][i][0], 1));
        for(j = 1; j < V1[N/2][i].size(); j++) {
            if(V_t1[i].back().num == V1[N/2][i][j]) V_t1[i].back().cnt++;
            else V_t1[i].push_back(data(V1[N/2][i][j], 1));
        }
    }
    ///// for N/2+1 ~ N
    V2[1][0].push_back(0);
    V2[1][0].push_back(d[N/2+1]);
    if(d[N/2+1] <= 18) V2[1][1].push_back(fact[d[N/2+1]]);
    for(i = 2; i <= N-N/2; i++) {
        for(j = 0; j <= i; j++) {
            for(k = 0; k < V2[i-1][j].size(); k++) V2[i][j].push_back(V2[i-1][j][k]);
            for(k = 0; k < V2[i-1][j].size(); k++) V2[i][j].push_back(V2[i-1][j][k]+d[i+N/2]);
            if(d[i+N/2] <= 18) for(k = 0; k < V2[i-1][j].size(); k++) V2[i][j+1].push_back(V2[i-1][j][k]+fact[d[i+N/2]]);
        }
    }
    for(i = 0; i <= N-N/2; i++) {
        if(V2[N-N/2][i].size() == 0) continue;
        sort(V2[N-N/2][i].begin(), V2[N-N/2][i].end());
        V_t2[i].push_back(data(V2[N-N/2][i][0], 1));
        for(j = 1; j < V2[N-N/2][i].size(); j++) {
            if(V_t2[i].back().num == V2[N-N/2][i][j]) V_t2[i].back().cnt++;
            else V_t2[i].push_back(data(V2[N-N/2][i][j], 1));
        }
    }
    ///// Merging
    for(i = 0; i < V_t2[0].size(); i++) M[0].push_back(V_t2[0][i]);
    for(i = 1; i <= N-(N/2); i++) {
        int pos1 = 0, pos2 = 0;
        while(pos1 < M[i-1].size() && pos2 < V_t2[i].size()) {
            if(M[i-1][pos1].num == V_t2[i][pos2].num) {
                M[i].push_back(data(M[i-1][pos1].num, M[i-1][pos1].cnt+V_t2[i][pos2].cnt));
                pos1++, pos2++;
            }
            else if(M[i-1][pos1].num > V_t2[i][pos2].num) {
                M[i].push_back(V_t2[i][pos2]);
                pos2++;
            }
            else {
                M[i].push_back(M[i-1][pos1]);
                pos1++;
            }
        }
        if(pos1 == M[i-1].size()) {
            for(j = pos2; j < V_t2[i].size(); j++) M[i].push_back(V_t2[i][j]);
        }
        else {
            for(j = pos1; j < M[i-1].size(); j++) M[i].push_back(M[i-1][j]);
        }
    }
    //// Getting answer
    for(i = 0; i <= N/2; i++) {
        if(i > K) break;
        j = K-i;
        if(j > N-N/2) j = N-N/2;
        int pos1 = 0, pos2 = M[j].size()-1;
        while(pos1 < V_t1[i].size() && pos2 >= 0) {
            if(V_t1[i][pos1].num + M[j][pos2].num == S) {
                ANS += V_t1[i][pos1].cnt * M[j][pos2].cnt;
                pos1++, pos2--;
            }
            else if(V_t1[i][pos1].num + M[j][pos2].num < S) pos1++;
            else pos2--;
        }
    }
    printf("%lld", ANS);
    return 0;
}
//*/