#include <bits/stdc++.h>
using namespace std;

bool used[300001];
int a[300001];
bool t;
int n,k,x;
void dfs(int i){
    used[i]=true;
    if (i==k) t=true;
    if (i==0) return ;
    if (t==false) dfs(a[i]);
}
int main(){
    cin>>n>>k;
    for (int i=1;i<n;++i){
        cin>>x;
        a[i]=x+i;
    }
    dfs(1);
    if (t==false) cout<<"NO";
    else cout<<"YES";
}