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

int a[100009];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    if(n==1){cout<<-1;return;}
    if(n==2){
        int d=a[1]-a[0];
        if(d==0)cout<<"1\n"<<a[0];
        else if(d%2==0)cout<<"3\n"<<(a[0]-d)<<" "<<(a[0]+d/2)<<" "<<(a[1]+d);
        else cout<<"2\n"<<(a[0]-d)<<" "<<(a[1]+d);
        return;
    }
    mii m;
    for(int i=1;i<n;i++)m[a[i]-a[i-1]]++;
    if(m.size()>2){cout<<0;return;}
    if(m.size()==1){
        int d=a[1]-a[0];
        if(d==0)cout<<"1\n"<<a[0];
        else cout<<"2\n"<<(a[0]-d)<<" "<<(a[n-1]+d);
    }
    else{
        auto it=m.begin();
        int aa,b,c,d;
        aa=it->fr;b=it->sc;it++;
        c=it->fr;d=it->sc;
        if(c!=2*aa){cout<<0;return;}
        if(d>1){cout<<0;return;}
        else{
            cout<<"1\n";
            for(int i=1;i<n;i++){
                int r=a[i]-a[i-1];
                if(r==c){cout<<(a[i]-aa);return;}
            }
        }
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