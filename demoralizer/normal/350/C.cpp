#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
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
    if(b%2)return ((a*t*t)%p);
    else return ((t*t)%p);
}

vc<pair<pii,pii> > co;
void solve(){
    int n,c=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;if(x*y==0)c++;
        co.pb({{abs(x),(x>0)?1:-1},{abs(y),(y>0)?1:-1}});
    }
    sort(co.begin(),co.end());
    cout<<(6*n-2*c);
    for(int i=0;i<n;i++){
        int x=co[i].fr.fr,y=co[i].sc.fr,a=co[i].fr.sc,b=co[i].sc.sc;
        if(x!=0){
            cout<<"\n1 "<<x<<" "<<((a==1)?'R':'L');
        }
        if(y!=0){
            cout<<"\n1 "<<y<<" "<<((b==1)?'U':'D');
        }
        cout<<"\n2";
        if(y!=0){
            cout<<"\n1 "<<y<<" "<<((b==-1)?'U':'D');
        }
        if(x!=0){
            cout<<"\n1 "<<x<<" "<<((a==-1)?'R':'L');
        }
        cout<<"\n3";
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