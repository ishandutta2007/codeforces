#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n;
int a[1000005];
ll v[1000005];
int f[1000005];
int sz[1000005];

int find(int x){
    if(f[x]==x){
        return x;
    }else{
        return f[x]=find(f[x]);
    }
}

inline void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    f[x]=y;
    sz[y]+=sz[x];
    v[y]+=v[x];
}

inline double val(int x){
    x=find(x);
    return (double)v[x]/sz[x];
}

int prv[1000005];

void deal(int x){
    while(prv[x]){
        int p=prv[x];
        if(val(p)<val(x))break;
        unite(p,x);
        prv[x]=prv[p];
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=i;
        sz[i]=1;
        v[i]=a[i];
        prv[i]=find(i-1);
        deal(i);
    }
    cout<<fixed<<setprecision(9);
    for(int i=1;i<=n;i++){
        cout<<val(i)<<'\n';
    }

    return 0;
}