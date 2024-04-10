#include <bits/stdc++.h>
using namespace std;


int n,m;
int a[105][105];
int b[105][105];
vector<pair<string,int> > ans;
vector<pair<string,int> > ans2;
bool t1=false,t2=false;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            cin>>a[i][j];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            b[i][j]=a[i][j];
    for (int i=1;i<=n;++i){
        int mn=1e9;
        for (int j=1;j<=m;++j)
            mn=min(mn,b[i][j]);
        for (int j=1;j<=mn;++j)
            ans.push_back(make_pair("row ",i));
        for (int j=1;j<=m;++j)
            b[i][j]-=mn;
    }
    for (int i=1;i<=m;++i){
        int mn=1e9;
        for (int j=1;j<=n;++j)
            mn=min(mn,b[j][i]);
        for (int j=1;j<=mn;++j)
            ans.push_back(make_pair("col ",i));
        for (int j=1;j<=n;++j)
            b[j][i]-=mn;
    }
    for (int i=1;i<=m;++i){
        int mn=1e9;
        for (int j=1;j<=n;++j)
            mn=min(mn,a[j][i]);
        for (int j=1;j<=mn;++j)
            ans2.push_back(make_pair("col ",i));
        for (int j=1;j<=n;++j)
            a[j][i]-=mn;
    }
    for (int i=1;i<=n;++i){
        int mn=1e9;
        for (int j=1;j<=m;++j)
            mn=min(mn,a[i][j]);
        for (int j=1;j<=mn;++j)
            ans2.push_back(make_pair("row ",i));
        for (int j=1;j<=m;++j)
            a[i][j]-=mn;
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
    if (b[i][j]!=0) {
        t1=true;
        break;
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
    if (a[i][j]!=0) {
        t2=true;
        break;
    }
    if (t1==true && t2==true) cout<<"-1";
    else if (t1==true || (t1==false && t2==false && ans2.size()<ans.size())) {
        cout<<ans2.size()<<'\n';
        for (int i=0;i<ans2.size();++i)
            cout<<ans2[i].first<<ans2[i].second<<'\n';
        } else {
        cout<<ans.size()<<'\n';
        for (int i=0;i<ans.size();++i)
            cout<<ans[i].first<<ans[i].second<<'\n';
        }
}