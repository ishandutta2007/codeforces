#include <bits/stdc++.h>
using namespace std;


int ans=1e9;
int n;
int x;
vector<int> v;


inline void solve(int x) {
    int res=0;
    for (int i=x;i<=n;i+=2) {
        res+=abs(i-v[(i+1)/2-1]);
    }
    ans=min(ans,res);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n/2;++i) {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    ans=1e9;
    solve(1);
    solve(2);
    cout<<ans;
}