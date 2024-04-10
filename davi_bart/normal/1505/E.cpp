#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
char a[6][6];
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string k;
        cin>>k;
        for(int j=0;j<M;j++)a[i][j]=k[j];
    }
    int x=0,y=0;
    int ans=0;
    while(x!=N-1 || y!=M-1){
        //cout<<x<<" "<<y<<endl;
        ans+=(a[x][y]=='*');
        if(y==M-1 || (x<M-1 && a[x+1][y]=='*'))x++;
        else y++;
    }
    ans+=(a[N-1][M-1]=='*');
    cout<<ans;
}