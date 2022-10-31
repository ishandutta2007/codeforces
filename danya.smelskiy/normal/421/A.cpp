#include <bits/stdc++.h>
using namespace std;

int n,a,b;
bool used[105];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b;
    for (int i=1;i<=a;++i) {
        int x;
        cin>>x;
        used[x]=true;
    }
    for (int i=1;i<=n;++i)
        cout<<(used[i] ? 1 : 2)<<" ";
}