#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
ll d[500050];
int chk[500050];

vector <int> checked;

int it[1048577];
int IT_MAX = 524288;
ll ANS = 0;
void update(int node, int val) {
    it[node] = node-IT_MAX+1;
    while(node > 1) {
        node /= 2;
        if(d[it[2*node]] > d[it[2*node+1]]) it[node] = it[2*node];
        else it[node] = it[2*node+1];
    }
    return;
}

int get_MAX(int n1, int n2) {
    int t = -1;
    if(n1 == n2) return it[n1];
    if(n1 % 2 == 1) {
        t = it[n1];
        n1++;
    }
    if(n1 == n2) {
        if(t == -1) return it[n1];
        else return (d[t] > d[it[n1]])? t:it[n1];
    }
    if(n2 % 2 == 0) {
        if(t == -1) t = it[n2];
        else t = (d[t] > d[it[n2]])? t : it[n2];
        n2--;
    }
    int t2 = get_MAX(n1/2, n2/2);
    if(t == -1) return t2;
    else return (d[t] > d[t2])? t : t2;
}

void get_ans(int n1, int n2) {
    if(n2 == n1+1) return;

    ANS += min(d[n1], d[n2]);
    int n3 = get_MAX(n1+IT_MAX, n2+IT_MAX-2);
    get_ans(n1, n3);
    get_ans(n3, n2);
    return;
}
    
int main() {
    int N, i;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%lld", &d[i]);
        update(i-1+IT_MAX, d[i]);
    }
    chk[1] = chk[N] = 1;
    int st = 1, en = N, mi;

    while(st < en) {
        if(d[st] > d[en]) {
            mi = en-1;
            while(d[mi] <= d[en]) {
                mi--;
                if(st == mi) break;
            }
            if(st == mi) break;
            else {
                chk[mi] = 1;
                ANS += d[en];
                en = mi;
            }         
        }
        else {
            mi = st+1;
            while(d[mi] <= d[st]) {
                mi++;
                if(en == mi) break;
            }
            if(en == mi) break;
            else {
                chk[mi] = 1;
                ANS += d[st];
                st = mi;
                
            }
        }
    }

    for(i = 1; i <= N; i++) if(chk[i] == 1) checked.push_back(i);

    for(i = 0; i < checked.size()-1; i++) {
        get_ans(checked[i], checked[i+1]);
    }

    printf("%lld", ANS);
    return 0;
}