#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int n,m,h;
int a[maxn],b[maxn];
bool v[maxn][maxn];
int ans[maxn][maxn];

int main(){
    cin>>n>>m>>h;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cin>>v[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v[i][j]==1){
                cout<< min(b[i],a[j])<<' ';
            }else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}