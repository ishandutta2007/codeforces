#include <stdio.h>
#include <vector>
using namespace std;

class Node {
public:
    Node() { Node(0,0,0,0); }
    Node(int a, int b, int c, int d) {
        max_s = a, min_s = b, num = c, lvl = d;
    }
    int max_s, min_s, num, lvl;
} d[200050];

vector <int> conn[200050];
vector <int> son[200050];
int Q[200050];

void aa(int x) {
    if(son[x].empty()) {
        d[x].max_s = d[x].min_s = d[x].num = 1;
        return;
    }
    
    d[x].num = 0;
    for(int i = 0; i < son[x].size(); i++) {
        aa(son[x][i]);
        d[x].num += d[son[x][i]].num;
    }

    if(d[x].lvl % 2 == 1) {
        int sum = 0, MIN = 200051;
        for(int i = 0; i < son[x].size(); i++) {
            sum += d[son[x][i]].min_s-1;
            MIN = (MIN < d[son[x][i]].max_s)? MIN:d[son[x][i]].max_s;
        }
        d[x].min_s = sum+1;
        d[x].max_s = MIN;
    }

    else {
        int sum = 0, MIN = 200051;
        for(int i = 0; i < son[x].size(); i++) {
            sum += d[son[x][i]].max_s;
            MIN = (MIN < d[son[x][i]].num - d[son[x][i]].min_s)? MIN:( d[son[x][i]].num - d[son[x][i]].min_s);
        }
        d[x].max_s = sum;
        d[x].min_s = d[x].num-MIN;
    }
    return;
}
int main() {
    int N, i, t1, t2;

    scanf("%d", &N);
    for(i = 1; i < N; i++) {
        scanf("%d %d", &t1, &t2);
        conn[t1].push_back(t2);
        conn[t2].push_back(t1);
    }

    int st = 1, en = 2;
    d[1].lvl = 1;
    Q[1] = 1;
    while(st < en) {
        t1 = Q[st];
        for(i = 0; i < conn[t1].size(); i++) {
            t2 = conn[t1][i];
            if(d[t2].lvl != 0) continue;
            d[t2].lvl = d[t1].lvl+1;
            son[t1].push_back(t2);
            Q[en++] = t2;
        }
        st++;
    }
    
    aa(1);
    printf("%d %d", d[1].num-d[1].max_s+1, d[1].num-d[1].min_s+1);
    return 0;
}