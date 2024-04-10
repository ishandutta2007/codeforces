#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

const int BASE = 1e7 + 19;
const int MOD = 1e9 + 7;

const int MAX_K = 1e3;
const int MAX_POWER = 1e3;

vector<int> powers;

void BuildPowers() {
    powers.resize(MAX_POWER + 1);
    powers[0] = 1;
    for (int i = 1; i < (int) powers.size(); ++i) {
        powers[i] = (1LL * powers[i - 1] * BASE) % MOD;
    }
}

class TKnapsack {
public:
    explicit TKnapsack(int k) {
        MaxValue.assign(k + 1, 0);
    }

    int GetSize() const {
        return MaxValue.size();
    }

    int GetScore() const {
        vector<int> maxValue(GetSize());
        maxValue[0] = MaxValue[0];
        for (int i = 1; i < GetSize(); ++i) {
            maxValue[i] = max(maxValue[i - 1], MaxValue[i]);
        }
        int result = 0;
        for (int i = 1; i < (int) MaxValue.size(); ++i) {
            result = (result + 1LL * powers[i - 1] * maxValue[i]) % MOD;
        }
        return result;
    }

    void AddElement(int score, int weight) {
        for (int i = GetSize() - 1; i >= 0; --i) {
            if (i + weight < GetSize()) {
                MaxValue[i + weight] = max(MaxValue[i + weight], score + MaxValue[i]);
            }
        }
    }
private:
    vector<int> MaxValue;
};

class TTree {
public:
    void Init(int mn, int mx) {
        Min = mn;
        Max = mx;

        Values.resize(4 * (mx - mn + 1));
    }

    void Add(int l, int r, const pair<int, int>& value) {
        Add(1, Min, Max, l, r, value);
    }

    void BuildResults(int k, const vector<bool>& isQuery, vector<int>& result) {
        TKnapsack knapsack(k);
        BuildResults(1, Min, Max, isQuery, knapsack, result);
    }
private:
    int Min;
    int Max;
    vector<vector<pair<int, int>>> Values;

    void Add(int v, int tl, int tr, int l, int r, const pair<int, int>& value) {
        if (tl == l && tr == r) {
            Values[v].push_back(value);
        } else {
            int tm = (tl + tr) >> 1;

            if (r <= tm) {
                Add(2 * v, tl, tm, l, r, value);
            } else if (l > tm) {
                Add(2 * v + 1, tm + 1, tr, l, r, value);
            } else {
                Add(2 * v, tl, tm, l, tm, value);
                Add(2 * v + 1, tm + 1, tr, tm + 1, r, value);
            }
        }
    }

    void BuildResults(int v, int tl, int tr, const vector<bool>& isQuery, TKnapsack knapsack, vector<int>& result) {
        for (const pair<int, int>& value : Values[v]) {
            knapsack.AddElement(value.first, value.second);
        }
        if (tl == tr) {
            if (isQuery[tl]) {
                result[tl] = knapsack.GetScore();
            }
        } else {
            int tm = (tl + tr) >> 1;

            BuildResults(2 * v, tl, tm, isQuery, knapsack, result);
            BuildResults(2 * v + 1, tm + 1, tr, isQuery, knapsack, result);
        }
    }
};

int main() {
    BuildPowers();

    // freopen("input2.txt", "r", stdin);

    int n, k;
    scanf("%d%d", &n, &k);

    vector<int> weight;
    vector<int> score;
    vector<int> id;
    vector<int> tp;
    vector<int> tin;

    for (int i = 0; i < n; ++i) {
        int s, w;
        scanf("%d%d", &s, &w);
        tp.push_back(1);
        weight.push_back(w);
        score.push_back(s);
        id.push_back(-1);
        tin.push_back(i);
    }

    int q;
    scanf("%d", &q);
    for (int query = 0; query < q; ++query) {
        int t;
        scanf("%d", &t);
        tp.push_back(t);
        id.push_back(-1);
        if (t == 1) {
            int s, w;
            scanf("%d%d", &s, &w);
            weight.push_back(w);
            score.push_back(s);
            tin.push_back(query + n);
        } else if (t == 2) {
            int x;
            scanf("%d", &x);
            --x;
            id.back() = x;
        }
    }

    vector<int> tout(weight.size(), n + q - 1);
    for (int i = n; i < n + q; ++i) {
        if (tp[i] == 2) {
            tout[id[i]] = i;
        }
    }

    int minTime = 0;
    int maxTime = n + q - 1;

    TTree tree;
    tree.Init(minTime, maxTime);

    vector<bool> isQuery(n + q, false);
    for (int i = n; i < n + q; ++i) {
        if (tp[i] == 3) {
            isQuery[i] = true;
        }
    }

    for (int i = 0; i < (int) weight.size(); ++i) {
        tree.Add(tin[i], tout[i], make_pair(score[i], weight[i]));
    }

    vector<int> results(n + q);

    tree.BuildResults(k, isQuery, results);

    for (int i = 0; i < n + q; ++i) {
        if (isQuery[i]) {
            printf("%d\n", results[i]);
        }
    }

    return 0;
}