#include<bits/stdc++.h>
using namespace std;

int n,a[150005];
vector<int> b[150005];

void mian(){
    for(int i=1;i<=150000;i++)b[i].clear();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]].emplace_back(i);
    }
    int ans=-1;
    for(int i=1;i<=150000;i++){
        for(int j=0;j+1<b[i].size();j++){
            int l=b[i][j],r=b[i][j+1];
            ans=max(ans,l-1+n-r+1);
        }
    }
    cout<<ans<<'\n';
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