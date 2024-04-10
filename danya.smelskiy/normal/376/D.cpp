#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;
int ans;
vector<int> v[5005];


int main(){
    ios_base::sync_with_stdio(false) ;cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        int last=0;
        cin>>s;
        for (int j=1;j<=m;++j) {
            if (s[j-1]=='1') ++last;
            else last=0;
            if (last!=0) v[j].push_back(last);
        }
    }
    for (int i=1;i<=m;++i) {
        sort(v[i].begin(),v[i].end());
        for (int j=v[i].size();j>0;--j) {
            ans=max(ans,v[i][j-1]*((int)v[i].size()-j+1));
        }
    }
    cout<<ans;
}