#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
struct data {
    int s,r, chk;
    bool operator < (const data & l) const {
        if(s != l.s) return s<l.s;
        else return r < l.r;
    }
} d[200050];
vector <int> CHK[200050];
int N;
vector <data*> ANS;
vector <int> ANS2;
void input() {
    int i;
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        scanf("%d %d", &d[i].s, &d[i].r);
        d[i].chk = i+1;
    }
    for(i = 1; i <= N; i++) CHK[i].push_back(i);
    sort(d, d+N);
    return;
}
bool compare(ll s1, ll s2, ll r1, ll r2, ll s3, ll r3) {
    if(r1*s2*(r3-r2)*(s1-s3) <= r2*s1*(r3-r1)*(s2-s3)) return true;
    else return false;
}
int chk2[200050];
void get_ans() {
    int i, j;
    ANS.push_back(&d[N-1]);
    for(i = N-2; i >= 0; i--) {
        data* t = ANS.back();
        if(t->s == d[i].s && t->r == d[i].r) {
            CHK[t->chk].push_back(d[i].chk);
            continue;
        }
        if(t->s == d[i].s) continue;
        if(d[i].r <= t->r) continue;
        while(ANS.size() > 1) {
            data* t1 = ANS[ANS.size()-2];
            data* t2 = ANS[ANS.size()-1];
            ll s1 = t1->s, s2 = t2->s, r1 = t1->r, r2 = t2->r;
            if(compare(s1, s2, r1, r2, d[i].s, d[i].r)) break;
            ANS.pop_back();
        }
        ANS.push_back(&d[i]);
    }
    for(i = 0; i < ANS.size(); i++) {
        for(j = 0; j < CHK[ANS[i]->chk].size(); j++) chk2[CHK[ANS[i]->chk][j]] = 1;
    }
    for(i = 1; i <= N; i++) if(chk2[i] == 1) printf("%d ", i);
    return;
}
int main() {
    input();
    get_ans();
    return 0;
}