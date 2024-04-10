#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
int sum[maxn];
pair<int,int> seq[maxn];
int n;
int main(){
    cin>>n;
    long long ans = 0;
    int cnt = 0;
    for (int i=1;i<=n;i++){
        int l;
        cin>>l;
        int min_val = INT_MAX;
        int max_val = -1;
        bool succ = false;
        while (l--){
            int x;
            cin>>x;
            succ |= x > min_val;
            min_val = min(min_val,x);
            max_val = max(max_val,x);
        }
        if (succ){
            cnt ++;
        }else{
            sum[max_val] ++;
        }
        seq[i] = make_pair(min_val,succ);
    }
    ans += 2ll * cnt * (n - cnt);
    ans += 1ll * cnt * cnt;
    for (int i=1e6;i>=1;i--){
        sum[i] += sum[i+1];
    }
    for (int i=1;i<=n;i++){
        if (!seq[i].second)ans += sum[seq[i].first+1];
    }
    cout<<ans<<endl;
    return 0;
}