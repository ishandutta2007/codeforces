#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18;
struct item_t{
    long long tp, pos, value;
    item_t(long long a, long long b, long long c) : tp(a), pos(b), value(c){}
};
bool operator< (item_t A, item_t B){
    if (A.pos != B.pos)
        return A.pos < B.pos;
    return A.value < B.value;
}
int main(){
   // freopen("in", "r", stdin);
    long long n;
    scanf("%lld", &n);
    vector<item_t> vec, seq;
    for (int i = 1; i <= n; ++i){
        long long a, b, t;
        scanf("%lld %lld %lld", &a, &b, &t);
        if (b - a >= t){
            vec.emplace_back(0, a, t);
            vec.emplace_back(1, b, t);
            seq.emplace_back(1, b - t + 1, t);
        }
    }
    sort(vec.begin(), vec.end());
    sort(seq.begin(), seq.end());
    reverse(seq.begin(), seq.end());
    long long time = vec[0].pos, ans = 0;
    long long pos = inf;
    multiset<long long> Q, Q2;
    for (long long i = 0; i < vec.size(); ++i){
        auto item = vec[i];
        if (!Q.empty()){
            auto val = *Q.begin();
            if (pos <= item.pos){
                auto length = item.pos - pos;
                auto cnt = length / val;
                ans += cnt + 1;
                time = pos + cnt * val;
                pos = inf;
                while (!seq.empty() && time >= seq.back().pos){
                    auto val = seq.back().value;
                    Q2.erase(Q2.find(val));
                    seq.pop_back();
                }
                if (!Q2.empty())
                    pos = time + *Q2.begin();
            }
        }
        else {
            time = item.pos;
            pos = inf;
        }
        if (item.tp == 0) {
            Q.insert(item.value);
            Q2.insert(item.value);
            pos = min(pos, item.pos + item.value);
        }
        if (item.tp == 1)
            Q.erase(Q.find(item.value));
    }
    printf("%lld\n", ans);
	return 0;
}