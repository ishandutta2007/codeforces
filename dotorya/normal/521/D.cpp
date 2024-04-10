#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
class Fraction {
public:
    Fraction() {
        Fraction(0,0,0);
    }
    Fraction(ll a, ll b, int c) {
        x = a, y = b, chk = c;
    }
    ll x, y;
    int chk;
    bool operator < (const Fraction & l) const {
        return x*l.y < y*l.x;
    }
};
class data {
public:
    data() {
        data(0,0);
    }
    data(ll a, int b) {
        num = a, chk = b;
    }
    ll num;
    int chk;
    bool operator < (const data & l) const {
        return num < l.num;
    }
};

ll ori[100050];
data AA[100050];
vector <data> BB[100050];
int chk_type[100050];

vector <Fraction> V;
vector <int> ANS;
int main() {
    int N, M, K, t1, t2, t3, i, j;
    scanf("%d %d %d", &K, &N, &M);
    for(i = 1; i <= K; i++) scanf("%lld", &ori[i]);
    for(i = 1; i <= N; i++) {
        scanf("%d %d %d", &t1, &t2, &t3);
        chk_type[i] = t1;
        if(t1 == 1 && AA[t2].num < t3) AA[t2] = data(t3,i);
        if(t1 == 2) BB[t2].push_back(data(t3,i));
        if(t1 == 3 && t3 != 1) V.push_back(Fraction(t3-1,1,i));
    }
    
    // Pushing A values to B vector
    for(i = 1; i <= K; i++) {
        if(AA[i].num <= ori[i]) continue;
        BB[i].push_back(data(AA[i].num-ori[i], AA[i].chk));
    }

    // Sorting B values
    for(i = 1; i <= K; i++) {
        if(BB[i].empty()) continue;
        sort(BB[i].begin(), BB[i].end());
        ll cur = ori[i];
        for(j = BB[i].size()-1; j >= 0; j--) {
            V.push_back(Fraction(BB[i][j].num, cur, BB[i][j].chk));
            cur += BB[i][j].num;
        }
    }

    sort(V.begin(), V.end());

    for(i = (int)V.size()-1; i >= (int)V.size()-M; i--) {
        if(i == -1) break;
        ANS.push_back(V[i].chk);
    }

    printf("%d\n", ANS.size());
    for(j = 1; j <= 3; j++) for(i = 0; i < ANS.size(); i++) if(chk_type[ANS[i]] == j) printf("%d ", ANS[i]);
    return 0;
}