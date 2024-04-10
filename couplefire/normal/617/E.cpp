#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int numPrefix[1<<22] = {0};
int numSuffix[1<<22] = {0};
int prefix[100005];
int suffix[100005];
int arr[100005];
long long aa = 0;

void remove(int idx,int cl, int cr){
    if(idx < 1 || idx > n) return;
    if(idx == cl){
        aa -= 0ll+numPrefix[k^prefix[idx-1]];
    }
    else aa -= 0ll+numSuffix[k^suffix[idx+1]];
    numPrefix[prefix[idx]]--;
    numSuffix[suffix[idx]]--;
}
void add(int idx,int cl, int cr){
    if(idx < 1 || idx > n) return;
    numPrefix[prefix[idx]]++;
    numSuffix[suffix[idx]]++;
    if(idx == cl-1){
        aa += 0ll+numPrefix[k^prefix[idx-1]];
    }
    else aa += 0ll+numSuffix[k^suffix[idx+1]];
}
long long get_answer(){
    return aa;
}

const int block_size = 316;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<long long> mo_s_algorithm(vector<Query> queries) {
    vector<long long> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l, cur_l+1, cur_r);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r, cur_l, cur_r-1);
        }
        while (cur_l < q.l) {
            remove(cur_l, cur_l, cur_r);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r, cur_l, cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<Query> v(m);
    for(int i = 0; i<n; i++) cin >> arr[i+1];
    prefix[0] = 0;
    for(int i = 1; i<=n; i++) prefix[i] = prefix[i-1]^arr[i];
    suffix[n+1] = 0;
    for(int i = n; i>=1; i--) suffix[i] = suffix[i+1]^arr[i];
    for(int i = 0; i<m; i++){
        int l, r; cin >> l >> r;
        v[i] = {l, r, i};
    }
    vector<long long> ans = mo_s_algorithm(v);
    for(auto i : ans) cout << i << endl;
}