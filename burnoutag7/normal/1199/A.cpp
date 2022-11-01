#include<bits/stdc++.h>
using namespace std;

int n,x,y;
int a[100005];

inline bool chk(int xx){
    for(int i=xx-1;i>=xx-x&&i>=1;i--){
        if(a[i]<=a[xx])return false;
    }
    for(int i=xx+1;i<=xx+y&&i<=n;i++){
        if(a[i]<=a[xx])return false;
    }
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>x>>y;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(chk(i)){
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;
}