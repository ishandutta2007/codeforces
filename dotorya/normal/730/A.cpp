#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1034567891;

int N;
int in[105];
vector <int> V;
bool isValid(int x) {
    int i;
    for(i = 1; i <= N; i++) {
        V.push_back(in[i] - x);
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    while(!V.empty() && V.back() == 0) V.pop_back();
    if(V.empty()) return true;

    while(V.size() >= 2) {
        int t1 = V[0], t2 = V[1];
        if(t1 == t2) {
            V.clear();
            return true;
        }
        V[0]--;
        V[1]--;
        sort(V.begin(), V.end());
        reverse(V.begin(), V.end());
        while(!V.empty() && V.back() == 0) V.pop_back();
    }
    V.clear();
    return false;
}
int main() {
    int i, j, k;
    scanf("%d", &N);

    int st = 1, en = 100, mi, rv = 0;
    for(i = 1; i <= N; i++) {
        scanf("%d", &in[i]);
        en = min(en, in[i]);
    }
    while(st <= en) {
        mi = (st+en)/2;
        if(isValid(mi)) {
            rv = mi;
            st = mi+1;
        }
        else en = mi-1;
    }

    printf("%d\n", rv);
    if(rv == 0) {
        printf("%d\n", 100*(N-1));
        for(i = 1; i < N; i++) {
            for(j = 1; j <= 100; j++) {
                for(k = 1; k <= N; k++) printf("%d", k == i || k == i+1);
                printf("\n");
            }
        }
        return 0;
    }

    int acnt = 0;
    vector <pii> V2;
    for(i = 1; i <= N; i++) V2.emplace_back(in[i]-rv, i);
    sort(V2.begin(), V2.end());
    reverse(V2.begin(), V2.end());
    while(V2.back().first == 0) V2.pop_back();


    while(!V2.empty()) {
        if(V2.size() >= 3 && V2[0].first == V2[1].first && V2[1].first == V2[2].first && (V2.size() == 3 || V2[2].first != V2[3].first)) {
            acnt++;
            V2[0].first--;
            V2[1].first--;
            V2[2].first--;
        }
        else {
            acnt++;
            V2[0].first--;
            V2[1].first--;
        }
        sort(V2.begin(), V2.end());
        reverse(V2.begin(), V2.end());
        while(V2.back().first == 0) V2.pop_back();
    }
    V2.clear();
    printf("%d\n", acnt);

    for(i = 1; i <= N; i++) V2.emplace_back(in[i]-rv, i);
    sort(V2.begin(), V2.end());
    reverse(V2.begin(), V2.end());
    while(V2.back().first == 0) V2.pop_back();


    while(!V2.empty()) {
        if(V2.size() >= 3 && V2[0].first == V2[1].first && V2[1].first == V2[2].first && (V2.size() == 3 || V2[2].first != V2[3].first)) {
            for(k = 1; k <= N; k++) printf("%d", k == V2[0].second || k == V2[1].second || k == V2[2].second);
            V2[0].first--;
            V2[1].first--;
            V2[2].first--;
            printf("\n");
        }
        else {
            for(k = 1; k <= N; k++) printf("%d", k == V2[0].second || k == V2[1].second);
            V2[0].first--;
            V2[1].first--;
            printf("\n");
        }
        sort(V2.begin(), V2.end());
        reverse(V2.begin(), V2.end());
        while(V2.back().first == 0) V2.pop_back();
    }
    V2.clear();
    return 0;
}