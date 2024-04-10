#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1000;
int n,v[N+5],sl[N+5],y=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    v[n+1]=1;
    for(int i=2;i<=n+1;i++)
        if(v[i]==1)
            sl[++y]=v[i-1];
    cout<<y<<"\n";
    for(int i=1;i<=y;i++) {
        cout<<sl[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
/**
**/