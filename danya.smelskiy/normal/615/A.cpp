#include <bits/stdc++.h>
using namespace std;
int n,m;
bool used[100001];
int x,y;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>x;
        for (int j=1;j<=x;++j){
            cin>>y;
            if (used[y]==false){
                used[y]=true;
                --m;
            }
        }
    }
    if (!m) cout<<"YES";
    else cout<<"NO";
}