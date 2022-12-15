#include <bits/stdc++.h>

const int N = 1000010;
typedef long long ll;

ll ans[N], ans1[N];

int main(){
    int n, w;
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; ++ i){
        int l;
        scanf("%d", &l);
        std::vector <int> vec(l);
        for (int j = 0; j < l; ++ j){
            scanf("%d", &vec[j]);
        }
        if (w < 2 * l) {
            int left = l - w, right = 0;
            std::deque <int> deque;
            deque.push_back(0);
            for (int j = 0; j < w; ++j) {
                int x = vec[deque.front()];
                if (j < w - l || w - 1 - j < w - l){
                    x = std::max(0, x);
                }
                ans[j] += x;
                if (deque.front() == left){
                    deque.pop_front();
                }
                ++ left, ++ right;
                if (right < l){
                    while (!deque.empty() && vec[deque.back()] <= vec[right]){
                        deque.pop_back();
                    }
                    deque.push_back(right);
                }
            }
        }
        else{
            int left = l - w, right = 0;
            std::deque <int> deque;
            deque.push_back(0);
            for (int j = 0; j < w; ++j) {
                int x = vec[deque.front()];
                x = std::max(x, 0);
                ans[j] += x;
                if (deque.front() == left){
                    deque.pop_front();
                }
                ++ left, ++ right;
                if (right < l){
                    while (!deque.empty() && vec[deque.back()] <= vec[right]){
                        deque.pop_back();
                    }
                    deque.push_back(right);
                }
                if (left <= 0 && right >= l - 1){
                    x = vec[deque.front()];
                    x = std::max(x, 0);
                    int diff = -left;
                    ans1[j + 1] += x, ans1[j + diff + 1] -= x;
                    j += diff;
                    left += diff, right += diff;
                }
            }
        }
    }
    for (int i = 1; i < N; ++ i){
        ans1[i] += ans1[i - 1];
    }
    for (int i = 0; i < N; ++ i){
        ans[i] += ans1[i];
    }
    for (int i = 0; i < w; ++ i){
        printf("%lld%c", ans[i], " \n"[i == w - 1]);
    }
    return 0;
}