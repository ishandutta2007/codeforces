#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int>v,vv;
int T,n;
void solve(){
    scanf("%d",&n);v.clear();vv.clear();
    if(n<=3){puts("-1");return;}
    v.pb(3);v.pb(1);v.pb(4);v.pb(2);
    for(int i=5;i<=n;i++)i&1?v.pb(i):vv.pb(i);
    for(int i=vv.size()-1;~i;i--)printf("%d ",vv[i]);
    for(int i=0;i<v.size();i++)printf("%d ",v[i]);puts("");
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}