#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6,INF=1e9;
int main(){
    int T; cin>>T;
    while (T--){
        int n; cin>>n;
        rep(i,1,n){
            int x; cin>>x; x=x>0?x:-x;
            if (i&1) printf("%d ",x);
            else printf("%d ",-x);
        }
        cout<<endl;
    }
    return 0;
}