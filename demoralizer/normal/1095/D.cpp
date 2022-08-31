#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
vc<int> v[200009];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,a,b;cin>>n;
    int z[n+5];
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        if(i==1){a=x;b=y;}
        v[x].pb(y);v[y].pb(x);
    }
    z[1]=1;
    if(a==v[1][0]||a==v[1][1]){
        z[2]=a;
    }
    else{
        z[2]=b;
    }
    int k=3;
    while(k<=n){
        int s=z[k-2],t=z[k-1];
        if(s==v[t][0]){
            z[k]=v[t][1];
        }
        else{
            z[k]=v[t][0];
        }
        k++;
    }
    for(int i=1;i<=n;i++){
        cout<<z[i]<<" ";
    }
}