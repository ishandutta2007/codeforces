#include <bits/stdc++.h>

using namespace std;

long long t[110000];

int main() {
    
    long long n, m, a, d;
    scanf("%I64d%I64d%I64d%I64d", &n, &m, &a, &d);
    for (int i = 0; i < m; ++i) {
        scanf("%I64d", t + i);
    }
    
    long long ans = 0;
    long long last_open = -1;
    long long cur_id = 1;
    long long id_step = d / a + 1;
    //cout << id_step << endl;
    for (int i = 0; i < m; ++i) {
        if (t[i] <= last_open) continue;
        if (cur_id > n) {
            ++ans;
            last_open = t[i] + d;
        } else {
            // update last_open to be the largest close time < t[i]
            // cur_id * a is the open time
            // cur_id * a + d is the close time
            // nxt_id * a > cur_id * a + d
            // nxt_id = (cur_id * a + d) / a + 1 = cur_id + d / a + 1
            // id_step = nxt_id - cur_id = d / a + 1
            // fin_id * a + d < t[i]
            long long fin_id = (t[i] - d - 1) / a;
            // (cur_id + id_step * (num_op - 1)) <= fin_id
            // id_step * (num_op - 1) <= fin_id - cur_id
            long long num_op = fin_id < cur_id ? 0LL : max(0LL, (fin_id - cur_id) / id_step + 1);
            //cout << "!!" << num_op << endl;
            ans += min(num_op, (n - cur_id + 1 + id_step - 1) / id_step);
            cur_id += num_op * id_step;
            // next open at
            long long nxt_open = cur_id > n ? t[i] : min(t[i], cur_id * a);
            last_open = nxt_open + d;
            ++ans;
            // update cur_id
            // cur_id * a > last_open
            cur_id = last_open / a + 1;
            //cout << last_open << " x " << cur_id<< endl;
        }
        //cout << last_open << endl;
    }
    if (cur_id <= n) {
        ans += (n - cur_id + 1 + id_step - 1) / id_step;
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}