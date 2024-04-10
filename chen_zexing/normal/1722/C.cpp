#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
string s[3][1005];
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        cin>>n;
        map <string,int> mp;
        for(int i=0;i<=2;i++)
            for(int j=1;j<=n;j++){
                cin>>s[i][j];
                mp[s[i][j]]++;
            }
        int ans[3]={};
        for(int i=0;i<=2;i++)
            for(int j=1;j<=n;j++){
                if(mp[s[i][j]]==1) ans[i]+=3;
                else if(mp[s[i][j]]==2) ans[i]++;
            }
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    }
    return 0;
}