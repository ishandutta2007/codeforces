#include <bits/stdc++.h>
using namespace std;

int n;
char ans[1000][1000];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    cin>>n;
    ans[1][1]='+';
    for (int it=1;it<=n;++it) {
        int len=(1<<(it-1));
        for (int i=1;i<=len;++i) {
            for (int j=1;j<=len;++j) {
                ans[i+len][j]=ans[i][j+len]=ans[i][j];
                if (ans[i][j]=='+') ans[i+len][j+len]='*';
                else ans[i+len][j+len]='+';
            }
        }
    }
    for (int i=1;i<=(1<<n);++i) {
        for (int j=1;j<=(1<<n);++j)
            cout<<ans[i][j];
        cout<<'\n';
    }
}