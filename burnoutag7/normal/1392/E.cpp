#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,q;
ll a[30][30];

void walk(const int &x,const int &y,ll k){
    cout<<x<<' '<<y<<endl;
    k-=a[x][y];
    if(x==n&&y==n){
        assert(k==0);
        return;
    }else
    if(y==n){
        walk(x+1,y,k);
    }else
    if(x==n){
        walk(x,y+1,k);
    }else
    if(a[x+1][y]){
        if(k>=a[x+1][y])walk(x+1,y,k);
        else walk(x,y+1,k);
    }else{
        if(k>=a[x][y+1])walk(x,y+1,k);
        else walk(x+1,y,k);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int lev=i+j-1;
            a[i][j]=(ll)(i&1)<<(n*2-1-lev);
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        walk(1,1,k);
    }

    return 0;
}