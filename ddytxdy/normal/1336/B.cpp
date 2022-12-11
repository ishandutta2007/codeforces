#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int T,n1,n2,n3,a[N],b[N],c[N];LL ans;
set<int>A,B,C;
set<int>::iterator it;
LL sq(int x){return 1ll*x*x;}
void solve(int *a,set<int>&B,set<int>&C,int n1){
    for(int i=1;i<=n1;i++){
        LL d1,d2;
        it=C.lower_bound(a[i]);
        if(it==C.end())continue;
        d1=*it;it=B.upper_bound(a[i]);
        if(it==B.begin())continue;
        d2=*--it;
        ans=min(ans,sq(d1-a[i])+sq(d2-a[i])+sq(d1-d2));
    }
}
void solve(){
    scanf("%d%d%d",&n1,&n2,&n3);A.clear();B.clear();C.clear();ans=3e18;
    for(int i=1;i<=n1;i++)scanf("%d",&a[i]),A.insert(a[i]);
    for(int i=1;i<=n2;i++)scanf("%d",&b[i]),B.insert(b[i]);
    for(int i=1;i<=n3;i++)scanf("%d",&c[i]),C.insert(c[i]);
    solve(a,B,C,n1);solve(a,C,B,n1);
    solve(b,A,C,n2);solve(b,C,A,n2);
    solve(c,A,B,n3);solve(c,B,A,n3);
    cout<<ans<<endl;
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}
// 1
// 1 1 1
// 1
// 1
// 1000000000