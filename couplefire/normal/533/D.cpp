#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    const int INF = 1e9+7;
    int n; cin >> n;
    vector<int> dp1(n+2), dp2(n+2), pos(n+2), len(n+2), st1, st2;
    for(int i = 0; i<=n+1; ++i)
        cin >> pos[i];
    for(int i = 1; i<=n; ++i)
        cin >> len[i], len[i] *= 2;
    len[0] = len[n+1] = INF;
    dp1[0] = 2*INF; st1.push_back(0);
    for(int i = 1; i<=n+1; ++i){
        while(dp1[st1.back()]<pos[i]) st1.pop_back();
        dp1[i] = pos[st1.back()]+len[i];
        while(dp1[st1.back()]<=dp1[i]) st1.pop_back();
        st1.push_back(i);
    }
    if(*max_element(dp1.begin()+1, dp1.begin()+n+1)>=pos[n+1]){
        cout << 0 << '\n';
        exit(0);
    }
    dp2[n+1] = -INF; st2.push_back(n+1);
    for(int i = n; i>=0; --i){
        while(dp2[st2.back()]>pos[i]) st2.pop_back();
        dp2[i] = pos[st2.back()]-len[i];
        while(dp2[st2.back()]>=dp2[i]) st2.pop_back();
        st2.push_back(i);
    }
    vector<int> st = {0};
    int ans = 2*INF;
    for(int i = 1; i<=n+1; ++i){
        if(dp2[i]<pos[i]){
            int lo = 0, hi = (int)st.size()-1;
            while(lo<hi){
                int mid = lo+(hi-lo+1)/2;
                if(dp1[st[mid]]>=dp2[i]) lo = mid;
                else hi = mid-1;
            }
            if(dp1[st[lo]]>st[lo])
                ans = min(ans, pos[i]-pos[st[lo]]);
        }
        if(dp1[i]>pos[i]){
            while(dp1[st.back()]<dp1[i]) st.pop_back();
            st.push_back(i);
        }
    }
    cout << ans/2 << (ans%2?".5":"") << '\n';
}