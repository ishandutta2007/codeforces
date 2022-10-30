#include <bits/stdc++.h>
using namespace std;
map<char,bool> used;
int n,m;
char a[100][100];
string s;
int ans;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>s;
        for (int j=1;j<=m;++j){
            a[i][j]=s[j-1];
        }
    }
    for (int i=2;i<=n;++i){
        for (int j=2;j<=m;++j){
            used['f']=false; used['a']=false; used['e']=false; used['c']=false;
            used[a[i][j]]=true; used[a[i-1][j-1]]=true; used[a[i-1][j]]=true;
            used[a[i][j-1]]=true;
            if (used['f']==true && used['a']==true && used['c']==true && used['e']==true) ++ans;
        }
    }
    cout<<ans;
}