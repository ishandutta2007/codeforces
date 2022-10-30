#include <bits/stdc++.h>
using namespace std;

int n,m;
string s[2505];
int z[30];
bool used[2505];
int kol[2505],kol2[100],kol3[100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if (n==1) {
        cin>>s[1];
        swap(s[1][0],s[1][1]);
        cout<<s[1];
        return 0;
    }
    for (int i=1;i<=n;++i)
        cin>>s[i];
    for (int i=1;i<=m;++i)
        ++kol2[s[1][i-1]-'a'];
    for (int i=2;i<=n;++i) {
        for (int j=0;j<26;++j)
            kol3[j]=kol2[j];
        for (int j=0;j<m;++j) {
            --kol3[s[i][j]-'a'];
            if (kol3[s[i][j]-'a']<0) {
                cout<<"-1";
                return 0;
            }
        }
    }
    for (int i=2;i<=n;++i) {
        for (int j=1;j<=m;++j)
            if (s[i][j-1]!=s[1][j-1]) ++kol[i];
        if (kol[i]>4) {
            cout<<"-1";
            return 0;
        }
        memset(z,0,sizeof(z));
        for (int j=1;j<=m;++j){
            ++z[s[i][j-1]-'a'];
            if (z[s[i][j-1]-'a']==2) {
                used[i]=true;
                continue;
            }
        }
    }
    for (int i=1;i<=m;++i) {
        for (int j=i+1;j<=m;++j) {
            bool t=false;
            int res=0;
            for (int k=2;k<=n;++k) {
                res=kol[k];
                if (s[k][i-1]!=s[1][i-1] && s[k][i-1]==s[1][j-1]) --res;
                if (s[k][j-1]!=s[1][j-1] && s[k][j-1]==s[1][i-1]) --res;
                if (s[k][i-1]==s[1][i-1] && s[k][i-1]!=s[1][j-1]) ++res;
                if (s[k][j-1]==s[1][j-1] && s[k][j-1]!=s[1][i-1]) ++res;
                if (res>2 || res==1) {
                    t=true;
                    break;
                }
                if (res==2) continue;
                if (used[k]==false) {
                    t=true;
                    break;
                }
            }
            if (t==false) {
                swap(s[1][i-1],s[1][j-1]);
                cout<<s[1];
                exit(0);
            }
        }
    }
    cout<<"-1";
}