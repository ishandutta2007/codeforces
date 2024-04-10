#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1 << 20;
int from[SIZE], a[SIZE], N;
struct data{
    int x, y, id;
    bool operator < (const data& b) const {
        if(from[x] == from[b.x]) {
            if(from[x] & 1) return (y < b.y);
            return b.y < y;
        }
        return from[x] < from[b.x];
    }
} qq[SIZE];
int cnt[SIZE];
long long an[SIZE];
long long score;
const int ADD = 1;
const int DELETE = -1;
void edit(int x, int ty) {
    if(ty == ADD) {
        cnt[x]++;
        score += x * (cnt[x] * 2 - 1LL);
    } else {
        score -= x * (cnt[x] * 2 - 1LL);
        cnt[x]--;
    }
}
int main(){
    int N, Q;
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) cin >> a[i];
    int sqn = sqrt(N + 0.1);
    for(int i = 0; i < N; i++) {
        from[i] = i / sqn;
    }
    for(int i = 0; i < Q; i++) {
        cin >> qq[i].x >> qq[i].y;
        qq[i].id = i;
    }
    sort(qq, qq + Q);
    int ll = qq[0].x, rr = qq[0].x - 1;
    for(int i = 0; i < Q; i++) {
        while(rr < qq[i].y) edit(a[++rr], ADD);
        while(ll > qq[i].x) edit(a[--ll], ADD);
        while(rr > qq[i].y) edit(a[rr--], DELETE);
        while(ll < qq[i].x) edit(a[ll++], DELETE);
        an[qq[i].id] = score;
    }
    for(int i = 0; i < Q; i++) cout << an[i] << '\n';
    return 0;
}