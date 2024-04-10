#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
pair<int,int> q[100005];
int sz;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i) {
        if (!sz || q[sz].first!=a[i]) {
            q[++sz]=make_pair(a[i],i);
        }
    }
    for (int i=2;i<sz;++i) {
        if (q[i-1].first>q[i].first && q[i+1].first>q[i].first) {
            cout<<3<<'\n';
            cout<<q[i-1].second<<" "<<q[i].second<<" "<<q[i+1].second<<'\n';
            return 0;
        }
        if (q[i-1].first<q[i].first && q[i+1].first<q[i].first) {
            cout<<3<<'\n';
            cout<<q[i-1].second<<" "<<q[i].second<<" "<<q[i+1].second<<'\n';
            return 0;
        }
    }
    cout<<"0";
}