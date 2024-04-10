#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> answer;
vector<pair<int, int> > pr;
vector<int> x;
bool C(int a, int b){
    return (pr[a] < pr[b]);
}
bool ch(int mid, int T){
    int a = 0;
    int S = 0;
    vector<int> th;
    for (int i=0; i < x.size(); i++){
        int ind = x[i];
        if (pr[ind].second < mid) continue;
        th.push_back(ind+1);
        a++;
        S += pr[ind].first;
        if (a == mid) break;
    }
    if (a < mid) return false;
    if (S > T) return false;
    answer = th;
    return true;
}
int32_t main(){
    int n, t;
    cin >> n >> t;
    for (int i=0; i < n; i++){
        int a, t;
        cin >> a >> t;
        pr.push_back(make_pair(t, a));
        x.push_back(i);
    }
    sort(x.begin(), x.end(), C);
    int L = 0;
    int R = n+1;
    while (R - L > 1){
        int M = (L + R) / 2;
        if (ch(M, t)) L = M;
        else R = M;
    }
    cout << answer.size() << endl;
    cout << answer.size() << endl;
    for (int i=0; i < answer.size(); i++) cout << answer[i] << " ";
    return 0;
}