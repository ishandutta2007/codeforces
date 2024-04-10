#include <bits/stdc++.h>
#define pb push_back
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N=1e6+6,B1=2,P1=1e9+7,B2=23,P2=1e9+9;
int p[N],a[N],pw1[N],H1[N],pw2[N],H2[N];
char s[N];
bool check(int x1,int x2,int y1,int y2){
    if (x2<x1) return true;
    if ((H1[x2]+P1-1LL*H1[x1-1]*pw1[x2-x1+1]%P1)%P1!=(H1[y2]+P1-1LL*H1[y1-1]*pw1[y2-y1+1]%P1)%P1)
        return false;
    if ((H2[x2]+P2-1LL*H2[x1-1]*pw2[x2-x1+1]%P2)%P2!=(H2[y2]+P2-1LL*H2[y1-1]*pw2[y2-y1+1]%P2)%P2)
        return false;
    return true;
}
int main(){
    int n,m=0; cin>>n>>s;
    for (int i=1;i<=n;++i) if (s[i-1]=='0') p[++m]=i;
    for (int i=1;i<m;++i) a[i]=p[i+1]-p[i]&1;
    for (int i=1;i<m;++i) H1[i]=(1LL*H1[i-1]*B1+a[i])%P1;
    pw1[0]=1;
    for (int i=1;i<m;++i) pw1[i]=1LL*pw1[i-1]*B1%P1;
    for (int i=1;i<m;++i) H2[i]=(1LL*H2[i-1]*B2+a[i])%P2;
    pw2[0]=1;
    for (int i=1;i<m;++i) pw2[i]=1LL*pw2[i-1]*B2%P2;
    int q; cin>>q;
    while (q--){
        int l1,l2,l; scanf("%d%d%d",&l1,&l2,&l); int r1=l1+l-1,r2=l2+l-1;
        if (m==0){ puts("Yes"); continue; }
        int p1=lower_bound(p+1,p+1+m,l1)-p,p2=upper_bound(p+1,p+1+m,r1)-p-1;
        int q1=lower_bound(p+1,p+1+m,l2)-p,q2=upper_bound(p+1,p+1+m,r2)-p-1;
        if (p2-p1+1!=q2-q1+1) puts("No");
        else{
            if (p1>p2||(check(p1,p2-1,q1,q2-1)&&(p[p1]-l1&1)==(p[q1]-l2&1)&&(r1-p[p2]&1)==(r2-p[q2]&1)))
                puts("Yes");
            else
                puts("No");
        }
    }
}
/*
5
11111
1000
1 2 3
*/