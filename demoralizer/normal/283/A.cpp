#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)                   (x).begin(),(x).end()
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

int a[200005],b[200005],sz=1;
void solve(){
    int n,totsum=0;
    cin>>n;cout.precision(9);cout<<fixed;
    for(int kkkk=0;kkkk<n;kkkk++){
        int t;
        cin>>t;
        if(t==2){
            cin>>t;
            a[sz]=t;
            totsum+=t;
            sz++;
        }
        else if(t==1){
            int x,y;
            cin>>x>>y;
            totsum+=x*y;
            b[x-1]+=y;
        }
        else{
            sz--;
            totsum-=a[sz];
            totsum-=b[sz];
            b[sz-1]+=b[sz];
            b[sz]=0;
        }
        double avg=1.0*totsum/sz;
        cout<<avg<<"\n";
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