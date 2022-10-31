#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;
int kol;
vector<int> v[405];
bool used[405];
void dfs(int x){
    used[x]=true;
    ++kol;
    for (int j=0;j<v[x].size();++j){
        int to=v[x][j];
        if (used[to]==false) dfs(to);
    }
}
int main(){
    cin>>n>>m;
    cin>>s;
    for (int i=0;i<s.size();++i){
        char c=s[i];
        int x=i*m;
        if (c=='<'){
            for (int j=1;j<m;++j)
                v[x+j+1].push_back(x+j);
        } else {
            for (int j=m;j>1;--j)
                v[x+j-1].push_back(x+j);
        }
    }
    cin>>s;
    for (int i=0;i<s.size();++i){
        char c=s[i];
        int x=i+1;
        if (c=='^'){
            for (int j=1;j<n;++j){
                v[x+m].push_back(x);
                x+=m;
            }
        } else {
            x+=(n-2)*m;
            for (int j=n;j>1;--j){
                v[x].push_back(x+m);
                x-=m;
            }
        }
    }
    for (int i=1;i<=n*m;++i){
        kol=0;
        dfs(i);
        if (kol!=n*m){
            cout<<"NO";
            return 0;
        }
        for (int j=1;j<=n*m;++j)
            used[j]=false;
    }
    cout<<"YES";
}