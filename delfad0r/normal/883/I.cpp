#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& vec) {
    out << "[";
    for (int x : vec) out << x << ", ";
    out << "]";
    return out;
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
    #define dbg_var(x) clog << #x << ": " << x << endl;
#endif

const int INF = 1e9;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];
    v[0] = 0;
    sort(v.begin(), v.end());
    vector<int> ans(n+1);
    ans[0] = 0;
    for(int i=1; i<k; i++) ans[i] = v[n]-v[1]+1;
    int scarto = -INF;
    
    priority_queue<pair<int,int>> pq;
    for(int i=k; i<=n; i++){
        pq.emplace(-ans[i-k],i-k);
        while(!pq.empty()){
            auto p = pq.top();
            if(v[i]-v[p.second+1] > -p.first){
                pq.pop();
                scarto = max(scarto, v[p.second+1]);
            }else break;
        }
        
        ans[i] = v[i]-scarto;
        if(!pq.empty()) ans[i] = min(ans[i], -pq.top().first);
    }
    cout << ans[n] << '\n';
}