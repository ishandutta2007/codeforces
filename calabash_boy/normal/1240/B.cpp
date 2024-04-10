#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
int a[maxn];
int id[maxn];
int first_pos[maxn];
int maxlen[maxn];
int pp[maxn];
void solve(){
    int n;
    cin>>n;
    vector<int> val(0);
    for (int i=1;i<=n;i++){
        cin>>a[i];
        id[i] = i;
        first_pos[i] = INT_MAX;
        val.push_back(a[i]);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()),val.end());
    for (int i=1;i<=n;i++){
        first_pos[a[i]] = min(first_pos[a[i]],i);
    }
    sort(id+1,id+1+n,[](int x,int y){
        if (a[x] != a[y]){
            return a[x] < a[y];
        }
        return x < y;
    });
    for (int i=1;i<=n;i++){
        pp[id[i]] = i;
    }
    maxlen[n] = 1;
    for (int i=n-1;i>=1;i--){
        maxlen[i] = 1;
        if (id[i] < id[i+1])maxlen[i] += maxlen[i+1];
    }
    int ans = val.size();
    for (int i=0;i<=(int)val.size()-1;i++){
        int st_val = val[i];
        int pos = pp[first_pos[st_val]];
        int ed_pos = maxlen[pos] + pos;
        if(ed_pos >n){
            ans = min(ans,i);
        }else{
            int v = a[id[ed_pos]];
            int id = lower_bound(val.begin(), val.end(), v) - val.begin();
            int temp_ans =i + val.size() - id;
            ans = min(ans,temp_ans);
        }
    }
    cout<<ans<<endl;
}
int main(){
    
    int T;
    cin>>T;
    while (T--){
        solve();
    }
    return 0;
}