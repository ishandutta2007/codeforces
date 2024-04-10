#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct data {
    int node, train_chk;
    long long chk;
    bool operator < (const data & l) const {
        if(chk != l.chk) return chk > l.chk;
        else return train_chk > l.train_chk;
    }
} t, t2;
int N, M, K, ANS;
vector <data> v[100050];
long long ans[100050];  
long long train[100050];
int Chk[100050];
priority_queue <data> d_heap;
void input() {
    int a, b, i;
    long long x;
    for(i = 1; i <= M; i++) {
        scanf("%d %d %lld", &a, &b, &x);
        t.node = b, t.chk = x, t.train_chk=0;
        v[a].push_back(t);
        t.node = a, t.chk = x, t.train_chk=0;
        v[b].push_back(t);
    }
    for(i = 1; i <= K; i++) {
        scanf("%d %lld", &a, &x);
        if(train[a] == 0) train[a] = x;
        else {
            ANS++;
            if(x < train[a]) train[a] = x;
        }
    }
    for(i = 1; i <= N; i++) {
        if(train[i] == 0) continue;
        t.chk = train[i], t.node = i, t.train_chk = 1;
        v[1].push_back(t);
    }
    return;
}
void get_ans() {
    t.node = 1, t.chk = 0, t.train_chk = 0;
    d_heap.push(t);
    while(!d_heap.empty()) {
        t = d_heap.top();
        d_heap.pop();
        if(Chk[t.node] == 1) {
            if(t.train_chk == 1) ANS++;
            continue;
        }
        for(int i = 0; i < v[t.node].size(); i++) {
            t2.node = v[t.node][i].node;
            if(Chk[t2.node] == 1) continue;
            t2.chk = v[t.node][i].chk + t.chk;
            t2.train_chk = v[t.node][i].train_chk;
            d_heap.push(t2);
            continue;
        }
        Chk[t.node] = 1;
    }
    printf("%d", ANS);
    return;
}
int main() {
    int a, b;
    scanf("%d %d %d", &N, &M, &K);
    input();
    get_ans();
    return 0;
}