#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int x,y;
bool last[1000005];
bool used[1000005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=m;++i){
        cin>>x;
        used[x]=true;
    }
    if (used[1]) {
        cout<<1;
        return 0;
    }
    last[1]=true;
    for (int i=1;i<=k;++i){
        cin>>x>>y;
        if (last[x]) {
            last[y]=true;
            last[x]=false;
        } else if (last[y]){
            last[y]=false;
            last[x]=true;
        }
        if (used[x]==true && last[x]==true) {
            cout<<x;
            return 0;
        } else if (used[y]==true && last[y]==true) {
            cout<<y;
            return 0;
        }
    }
    for (int i=1;i<=n;++i)
    if (last[i]==true) {
        cout<<i;
        return 0;
    }
}