#include<bits/stdc++.h>
using namespace std;

int n,m,k,mx,a[100005],b[505][505],c[100005];

void mian(){
    cin>>m>>k;
    mx=0;
    vector<pair<int,int>> v;
    for(int i=1;i<=k;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        v.emplace_back(a[i],i);
    }
    n=1;
    while(m>n*n-(n/2)*(n/2)||mx>(n+1)/2*n)n++;
    for(int i=1;i<=n;i++)memset(b[i]+1,0,n<<2);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    m=0;
    for(pair<int,int> &p:v){
        while(p.first--)c[++m]=p.second;
    }
    int cm=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        if(i&1&&j&1^1&&cm<m)b[i][j]=c[++cm];
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        if(i&1&&j&1&&cm<m)b[i][j]=c[++cm];
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        if(i&1^1&&j&1&&cm<m)b[i][j]=c[++cm];
    }
    cout<<n<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<b[i][j]<<' ';
        }
        cout<<'\n';
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}