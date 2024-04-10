#include <bits/stdc++.h>
using namespace std;
int n,x,y;
bool used[100001];
bool used2[100001];
int main(){
    cin>>n;
    for (int i=1;i<=n*n;++i){
        cin>>x>>y;
        if (used[x]==false && used2[y]==false) { cout<<i<<'\n'; used[x]=true; used2[y]=true;}
    }
}