#include <bits/stdc++.h>
using namespace std;

int n;
int x;
bool used[300005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int r=n;
    bool t=false;
    cout<<1<<" ";
    int ans=0;
    for (int i=1;i<=n;++i) {
        cin>>x;
        if (x==1) {
            t=true;
            ++ans;
        } else {
            used[x]=true;
            if (x<=r) ++ans;
        }
        while (r && used[r]) {
            --ans;
            --r;
        }
        if (i==n) --ans;
        cout<<ans+1<<" ";
    }
}