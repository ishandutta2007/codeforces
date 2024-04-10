#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int hcf(int a,int b){
    if(a==0)return b;
    if(b==0)return a;
    return hcf(b%a,a);
}
int pw(int a,int b){
    int r=1;
    for(int i=0;i<b;i++)r*=a;
    return r;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,x,y;
    cin>>n>>m;
    vc<int> a[n+1];
    for(int i=0;i<m;i++){
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    set<int> s;
    int c=0;
    for(int i=1;i<=n;i++){
        if(s.find(i)!=s.end()||a[i].size()<2)continue;
        s.insert(i);
        int z=a[i][0],y=i,d=1;
        while(1==1){
            if(s.find(z)!=s.end()||a[z].size()<2)break;
            d++;
            s.insert(z);
            if(a[z][0]!=y){
                y=z;z=a[z][0];
            }
            else{
                y=z;z=a[z][1];
            }
            if(z==i){
                c+=d%2;break;
            }
        }
    }
    cout<<(c+(n-c)%2);
}