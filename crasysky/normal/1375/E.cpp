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
const int N=1e3+3,INF=1e9;
int a[N],b[N*N][2]; vector<int> G[N];
pr p[N];
int main(){
    int n,cnt=0; cin>>n; rep(i,1,n) cin>>a[i];
    rep(i,1,n){
        int c=0;
        per(j,n,i+1) if (a[j]<a[i]) p[++c]=mp(a[j],j);
        sort(p+1,p+1+c);
        per(j,c,1)
            b[++cnt][0]=i,b[cnt][1]=p[j].se;
    }
    cout<<cnt<<endl;
    rep(i,1,cnt) printf("%d %d\n",b[i][0],b[i][1]);
    return 0;
}
/*
5
3 4 3 1 2
*/