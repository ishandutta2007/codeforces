#include <bits/stdc++.h>
using namespace std;
#pragma optimaze("03")
const int inf=1e9;
string s;
int n,m;
int ans,last;
int kol;
pair<char,int> v[600005][5];
int kk[600005];
int pred[600005][15];
int l;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    getline(cin,s);
    getline(cin,s);
    l=s.size();
    for (int i=1;i<=n;++i){
        v[i][0]=make_pair(s[i-1],inf);
        kol=1;
        for (int j=1;j<=m;++j){
            if (char('A'-1+j)!=s[i-1]) {
                ++kol;
                v[i][kol-1]=make_pair(char('A'-1+j),inf);
                if (kol>=3) break;
            }
        }
        kk[i]=kol;
        if (i==1) {
            v[1][0].second=0;
            for (int j=1;j<kol;++j)
                v[i][j].second=1;
            continue;
        }
        for (int j=0;j<kol;++j)
        if (v[i-1][j].first!=v[i][0].first) {
            if (v[i-1][j].second<v[i][0].second) {
                v[i][0].second=v[i-1][j].second;
                pred[i][0]=j;
            }
        }
        for (int j=1;j<kol;++j){
            for (int k=0;k<kk[i-1];++k){
                if (v[i][j].first!=v[i-1][k].first) {
                    if (v[i-1][k].second+1<v[i][j].second) {
                        v[i][j].second=v[i-1][k].second+1;
                        pred[i][j]=k;
                    }
                }
            }
        }
    }
    ans=inf;
    last;
    for (int i=0;i<kk[n];++i)
        if (v[l][i].second<ans) {
            ans=v[l][i].second;
            last=i;
        }
    cout<<ans<<'\n';
    string q="";
    for (int i=n;i>0;--i) {
        q+=v[i][last].first;
        last=pred[i][last];
    }
    reverse(q.begin(),q.end());
    cout<<q;
}