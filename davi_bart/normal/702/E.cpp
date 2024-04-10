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
int p[50][100010];
int mi[50][100010];
int v[50][100010];
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v[0][i]=a;
    }
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        mi[0][i]=a;
        p[0][i]=a;
    }
    for(int i=1;i<46;i++){
        for(int j=0;j<N;j++){
            p[i][j]=p[i-1][j]+p[i-1][v[i-1][j]];
            mi[i][j]=min(mi[i-1][j],mi[i-1][v[i-1][j]]);
            v[i][j]=v[i-1][v[i-1][j]];
        }
    }
    for(int i=0;i<N;i++){
        int tot=0,m=1e18;
        int pos=i;
        for(int x=40;x>=0;x--){
            if(K&((int)1<<x)){
                tot+=p[x][pos];
                m=min(m,mi[x][pos]);
                pos=v[x][pos];
            }
        }
        cout<<tot<<" "<<m<<endl;
    }

}