#include<bits/stdc++.h>
using namespace std;

int n,a[100005];

void solve(){
    cin>>n;
    set<int> s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i]<=a[i-1];
        s.insert(a[i]);
    }
    cout<<s.size()<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)solve();

    return 0;
}