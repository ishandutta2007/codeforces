#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=300000;
int h[MAXN];
long long b[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    for (int i=0;i<n;++i){
        cin>>h[i];
    }
    for (int i=0;i<n;++i){
        cin>>b[i];
    }
    vector<pair<int, pair<long long,long long>>> st;
    multiset<long long, greater<long long>> maxbeauty;
    st.emplace_back(h[0],make_pair(b[0],0ll));
    maxbeauty.emplace(b[0]);
    for(int i=1;i<n;++i){
        long long cnew=*(maxbeauty.begin());
        long long bestbeauty=LLONG_MIN;
        while (!st.empty()&&st.back().first>=h[i]){
            bestbeauty=max(bestbeauty,st.back().second.second);
            maxbeauty.erase(maxbeauty.find(st.back().second.first+st.back().second.second));
            st.pop_back();
        }
        cnew=max(cnew,bestbeauty);
        st.emplace_back(h[i],make_pair(b[i],cnew));
        maxbeauty.emplace(b[i]+cnew);
    }
    cout<<*(maxbeauty.begin())<<'\n';
}