#include <bits/stdc++.h>

using namespace std;

const int max_n = 120222, inf = 1000111222;
const int block_size = 333;
const int max_blocks = max_n / block_size + 1;

int n, q, a[max_n];
long long ans[max_n];
vector<pair<int, int>> queries[max_n], mins, maxs;

int num[max_n], lb[max_blocks], rb[max_blocks];
int value[max_n], min_value[max_blocks], cnt_mins[max_blocks], add_value[max_blocks];
int res[max_n], add_res[max_blocks], sum_block[max_blocks];

void reset(int num) {
    for (int i = lb[num]; i < rb[num]; ++i) {
        value[i] += add_value[num];
        if (value[i] == min_value[num]) {
            res[i] += add_res[num];
        }
    }
    sum_block[num] += 1LL * cnt_mins[num] * add_res[num];
    add_value[num] = 0;
    add_res[num] = 0;
}

void calc_min_values(int num) {
    min_value[num] = inf;
    cnt_mins[num] = 0;
    for (int i = lb[num]; i < rb[num]; ++i) {
        if (min_value[num] > value[i]) {
            min_value[num] = value[i];
            cnt_mins[num] = 1;
        } else if (min_value[num] == value[i]) {
            ++cnt_mins[num];
        }
    }
    //cout << "calc min values: " << num << "  " << min_value[num] << " " << cnt_mins[num] << endl;
}

void precalc_blocks() {
    for (int i = 0; i < max_blocks; ++i) {
        int l = min(n, block_size * i);
        int r = min(n, block_size * (i + 1));
        for (int j = l; j < r && j < max_n; ++j) {
            num[j] = i;
        }
        calc_min_values(i);
        lb[i] = l;
        rb[i] = r;
    }
}

void add(int l, int r, int x) {
    //cout << "[" << l << " " << r << "] += " << x << endl;
    if (num[l] == num[r]) {
        reset(num[l]);
        for (int i = l; i <= r; ++i) {
            value[i] += x;
        }
        calc_min_values(num[l]);
        return;
    }
    for (int i = num[l] + 1; i < num[r]; ++i) {
        add_value[i] += x;
        min_value[i] += x;
        //cout << "#" << i << " " << add_value[i] << " " << min_value[i] << endl;
    }
    reset(num[l]);
    reset(num[r]);
    for (int i = l; num[i] == num[l]; ++i) {
        value[i] += x;
    }
    for (int i = r; num[i] == num[r]; --i) {
        value[i] += x;
    }
    calc_min_values(num[l]);
    calc_min_values(num[r]);
}

void inc_res() {
    //cout << "inc" << endl;
    for (int i = 0; lb[i] < n; ++i) {
        if (min_value[i] == -1) {
            ++add_res[i];
        }
    }
}

long long get_sum(int l, int r) {
    long long sum = 0;
    if (num[l] == num[r]) {
        reset(num[l]);
        for (int i = l; i <= r; ++i) {
            sum += res[i];
        }
        return sum;
    }
    for (int i = num[l] + 1; i < num[r]; ++i) {
        //cout << i << ": " << sum_block[i] << " " << add_res[i] << " " << cnt_mins[i] << endl;
        sum += sum_block[i];
        sum += 1LL * add_res[i] * cnt_mins[i];
    }
    reset(num[l]);
    reset(num[r]);
    for (int i = l; num[i] == num[l]; ++i) {
        //cout << i << "$" << res[i] << endl;
        sum += res[i];
    }
    for (int i = r; num[i] == num[r]; --i) {
        //cout << i << "$" << res[i] << endl;
        sum += res[i];
    }
    calc_min_values(num[l]);
    calc_min_values(num[r]);
    return sum;
}

void update_maxs(int x) {
    while (maxs.size() && x >= maxs.back().first) {
        int l = 0;
        if (maxs.size() >= 2) {
            l = maxs[maxs.size() - 2].second + 1;
        }
        int r = maxs.back().second;
        add(l, r, x - maxs.back().first);
        maxs.pop_back();
    }
}

void update_mins(int x) {
    while (mins.size() && x <= mins.back().first) {
        int l = 0;
        if (mins.size() >= 2) {
            l = mins[mins.size() - 2].second + 1;
        }
        int r = mins.back().second;
        add(l, r, mins.back().first - x);
        mins.pop_back();
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        queries[r].push_back({l, i});
    }
    precalc_blocks();
    for (int r = 0; r < n; ++r) {
        add(0, r, -1);
        update_maxs(a[r]);
        update_mins(a[r]);
        maxs.push_back({a[r], r});
        mins.push_back({a[r], r});
        inc_res();
        for (const pair<int, int> &query : queries[r]) {
            ans[query.second] = get_sum(query.first, r);
        }
    }
    for (int i = 0; i < q; ++i) {
        printf("%I64d\n", ans[i]);
    }
    return 0;
}