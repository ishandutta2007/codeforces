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

void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    int a,b,c;
    int t=(r-l+1);
    if(t%3==0){
        a=t/3;b=t/3;c=t/3;
    }
    else if(t%3==1){
        a=t/3;
        b=t/3;
        c=t/3;
        if(l%3==0){
            a++;
        }
        else if(l%3==1)b++;
        else c++;
    }
    else{
        a=t/3+1;
        b=t/3+1;
        c=t/3+1;
        if(l%3==1){
            a--;
        }
        else if(l%3==2)b--;
        else c--;
    }
    int na,nb,nc,oa=a,ob=b,oc=c;
    for(int i=1;i<n;i++){
        na=((a*oa)%M+((b*oc)%M+(c*ob)%M)%M)%M;
        nb=((c*oc)%M+((a*ob)%M+(b*oa)%M)%M)%M;
        nc=((b*ob)%M+((a*oc)%M+(c*oa)%M)%M)%M;
        a=na;b=nb;c=nc;
    }
    cout<<a;
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}