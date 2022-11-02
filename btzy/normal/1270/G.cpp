#include <bits/stdc++.h>
using namespace std;
int arr[1000000];
int vis[1000000];
int n;
void solve(){
    fill_n(vis,n,-1);
    int c=0;
    vis[0]=c++;
    int k=-arr[0];
    while(vis[k]==-1){
        vis[k]=c++;
        k-=arr[k];
    }
    cout<<c-vis[k]<<'\n'<<k+1;
    int x=k-arr[k];
    while(x!=k){
        cout<<' '<<x+1;
        x-=arr[x];
    }
    cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    setvbuf(stdin,nullptr,_IOFBF,1000000*8);
    setvbuf(stdout,nullptr,_IOFBF,1000000*8);
    int tc;
    cin>>tc;
    for(int ct=0;ct!=tc;++ct){
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        solve();
    }
}