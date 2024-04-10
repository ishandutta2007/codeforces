#include <bits/stdc++.h>
using namespace std;

int n,k,a,b,c,d;
bool used[1005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>a>>b>>c>>d;
    if (n<=4 || k<=n) {
        cout<<"-1";
        return 0;
    }
    used[a]=used[b]=used[c]=used[d]=true;
    cout<<a<<" "<<c<<" ";
    for (int i=1;i<=n;++i)
        if (used[i]==false) cout<<i<<" ";
    cout<<d<<" "<<b;
    cout<<'\n';
    cout<<c<<" "<<a<<" ";
    for (int i=1;i<=n;++i)
        if (used[i]==false) cout<<i<<" ";
    cout<<b<<" "<<d;
}