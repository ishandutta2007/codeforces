#include <bits/stdc++.h>
using namespace std;




long long x,d;
vector<long long> ans;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>d;
    long long last2=1;
    while (x) {
        long long last=0;
        for (long long i=0;i<=31;++i) {
            long long y=(1ll<<i);
            y--;
            if (y<=x) last=i;
            else break;
        }
        x-=(1ll<<last)-1ll;
        while (last) {
            --last;
            ans.push_back(last2);
        }
        if (last2>1e18) {
            cout<<"-1";
            return 0;
        }
        if (ans.size()>10000) {
            cout<<"-1";
            return 0;
        }
        last2+=d;
        last2++;
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i]<<" ";
}