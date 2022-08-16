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

pair<int,pii> p[100005];
int ind[100005];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        p[i]={0,{i,t}};
    }
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        p[i].fr=t;
    }
    sort(p+1,p+1+n);
    for(int i=1;i<=n;i++){
        ind[p[i].sc.fr]=i;
    }
    int mav=1,death=0;
    for(int z=0;z<m;z++){
        int t,d;
        cin>>t>>d;
        if(death){
            cout<<"0\n";
            continue;
        }
        int cost=0;
        int pos=ind[t];
        int r=p[pos].sc.sc;
        if(r>=d){
            p[pos].sc.sc-=d;
            cost+=p[pos].fr*d;
            d=0;
        }
        else{
            cost+=p[pos].fr*p[pos].sc.sc;
            d-=p[pos].sc.sc;
            p[pos].sc.sc=0;
        }
        while(d){
            pos=mav;
            if(pos>n){
                death=1;break;
            }
            int r=p[pos].sc.sc;
            if(r>=d){
                p[pos].sc.sc-=d;
                cost+=p[pos].fr*d;
                d=0;
            }
            else{
                cost+=p[pos].fr*p[pos].sc.sc;
                d-=p[pos].sc.sc;
                p[pos].sc.sc=0;
            }
            if(d==0)break;
            mav++;
        }
        if(death){
            cout<<"0\n";continue;
        }
        cout<<cost<<"\n";
    }
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