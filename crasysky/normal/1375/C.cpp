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
int a[N];
int main(){
    int T; cin>>T;
    while (T--){
        int n; scanf("%d",&n); rep(i,1,n) scanf("%d",&a[i]);
        if (a[n]<a[1]) puts("NO");
        else puts("YES");
    }
    return 0;
}