#include<bits/stdc++.h>
using namespace std;

int n,m,b[250005],a[250005];
vector<int> s[250005];

bool solve(int k){
    bool valid=true;
    vector<int> cd(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]!=b[j])cd[i]++;
        }
        valid&=cd[i]<=2;
        if(cd[i]>2+k)return false;
    }
    if(valid){
        memcpy(a,b,sizeof(a));
        return true;
    }
    for(int i=1;i<=n;i++)if(cd[i]>2){
        for(int j=1;j<=m;j++){
            if(s[i][j]!=b[j]){
                int tmp=b[j];
                b[j]=s[i][j];
                if(solve(k-1))return true;
                b[j]=tmp;
            }
        }
        break;
    }
    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    n--;
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        s[i].resize(m+1);
        for(int j=1;j<=m;j++)cin>>s[i][j];
    }
    if(solve(2)){
        cout<<"Yes\n";
        for(int i=1;i<=m;i++)cout<<a[i]<<' ';
    }else cout<<"No\n";

    return 0;
}