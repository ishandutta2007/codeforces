#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define f first 
#define s second
#define mp make_pair
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

int T,N,Q,a,b,c,d,e,K;
vi V,A;

bool sq(ll x){
    ll t=sqrt(x);
    if(t*t==x)return 1;
    return 0;
}

int main(){
    cin>>T;
    while(T--){
        cin>>N;
        if(N%2==1){
            cout<<"NO\n";
            continue;
        }
        ll area=N/2;
        if(sq(area)||sq(area*2)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}