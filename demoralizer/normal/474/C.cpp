#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define piii              pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}

pii rot(pii x,pii a){
    int u=x.fr-a.fr,v=x.sc-a.sc;
    return {a.fr-v,a.sc+u};
}
int distSq(pii a,pii b){
    return (a.fr-b.fr)*(a.fr-b.fr)+(a.sc-b.sc)*(a.sc-b.sc);
}
int check(pii *x){
    pii p1=x[0],p2=x[1],p3=x[2],p4=x[3];
    int d2 = distSq(p1, p2); // from p1 to p2
    int d3 = distSq(p1, p3); // from p1 to p3
    int d4 = distSq(p1, p4); // from p1 to p4
    if(d2&&d3&&d4&&distSq(p2,p3)&&distSq(p2,p4)&&distSq(p3,p4));else return 0;
    // If lengths if (p1, p2) and (p1, p3) are same, then
    // following conditions must met to form a square.
    // 1) Square of length of (p1, p4) is same as twice
    // the square of (p1, p2)
    // 2) Square of length of (p2, p3) is same as twice the square of (p1, p2)

    if (d2 == d3 && 2 * d2 == d4 && 2 * d2 == distSq(p2, p3)) {
        int d = distSq(p2, p4);
        return (d == distSq(p3, p4) && d == d2);
    }

    // The below two cases are similar to above case
    if (d3 == d4 && 2 * d3 == d2 && 2 * d3 == distSq(p3, p4)) {
        int d = distSq(p2, p3);
        return (d == distSq(p2, p4) && d == d3);
    }
    if (d2 == d4 && 2 * d2 == d3 && 2 * d2 == distSq(p2, p4)) {
        int d = distSq(p2, p3);
        return (d == distSq(p3, p4) && d == d2);
    }

    return 0;
}
void solve(){
    pii x[4],a[4];int ans=-1;
    for(int i=0;i<4;i++){
        cin>>x[i].fr>>x[i].sc>>a[i].fr>>a[i].sc;
    }
    for(int i=0;i<256;i++){
        pii xz[4],az[4];
        for(int i=0;i<4;i++){
            xz[i]=x[i];
            az[i]=a[i];
        }
        int p=i,c=0;
        for(int i=0;i<4;i++){
            int d=p%4;
            c+=d;
            for(int zz=0;zz<d;zz++)xz[i]=rot(xz[i],az[i]);
            p/=4;
        }
        if(check(xz)){
            if(ans==-1)ans=c;
            ans=min(c,ans);
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}