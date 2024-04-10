#include <bits/stdc++.h>
using namespace std;


int n,ans;
int kol[200005];
int x;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    ++kol[0];
    ans=1;
    for (int i=1;i<=n;++i) {
        cin>>x;
        if (kol[x]) {
            --kol[x];
            ++kol[i];
        } else {
            ++kol[i];
            ++ans;
        }
    }
    cout<<ans;
}