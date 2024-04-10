#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void mian(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end(),greater<pair<int,int>>());
    vector<int> ans(n);
    ll ansv=0;
    for(int i=0;i<n;i++){
        ans[a[i].second]=(i/2+1)*(i&1?-1:1);
        ansv+=a[i].first*(i/2+1ll);
    }
    cout<<ansv*2<<"\n0 ";
    for(int x:ans)cout<<x<<' ';
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}