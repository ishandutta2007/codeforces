#include <bits/stdc++.h>
using namespace std;
const int MXN=1299709;

int n,m;
bool prime[1500000];
vector<pair<pair<int,int>,int> > ans;
int nn;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=2;i<=sqrt(MXN);++i)
    if (prime[i]==false) {
        for (int j=i*i;j<=MXN;j+=i)
            prime[j]=true;
    }
    cin>>n>>m;
    for (int i=n;;++i)
    if (prime[i]==false) {
        nn=i;
        break;
    }
    int last=nn-(n-2);
    for (int i=2;i<=n;++i) {
        --m;
        if (i==n) ans.push_back(make_pair(make_pair(i-1,i),last));
        else ans.push_back(make_pair(make_pair(i-1,i),1));
    }
    int l=1;
    int r=3;
    while (m--) {
        ans.push_back(make_pair(make_pair(l,r),1e9));
        ++r;
        if (r==n+1) {
            ++l;
            r=l+2;
        }
    }
    cout<<nn<<" "<<nn<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<'\n';
}