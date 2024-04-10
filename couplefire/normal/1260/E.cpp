#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    long long pos;
    long long arr[n+1];
    for(long long i = 1; i<=n; i++){
        cin >> arr[i];
        if(arr[i] == -1) pos = i;
    }
    long long pos2 = pow(2, (long long)log2(pos));
    vector<long long> af;
    af.push_back(-2);
    for(long long i = pos2; i<pos; i++) af.push_back(arr[i]);
    for(long long i = pos+1; i<=n; i++) af.push_back(arr[i]);
    multiset<long long> mst;
    long long cur = n-pos2;
    stack<long long> checkpoints;
    long long add = pos2*2;
    long long cc = pos2;
    while(cc <= cur){
        checkpoints.push(cc);
        cc += add;
        add *= 2;
    }
    long long sum = 0;
    while(!checkpoints.empty()){
        long long t = checkpoints.top();
        checkpoints.pop();
        while(cur >= t){
            mst.insert(af[cur]);
            cur--;
        }
        sum += *mst.begin();
        mst.erase(mst.begin());
    }
    cout << sum << endl;
}