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
#define lb lower_bound
#define ub upper_bound

const int MAXN=200100;

int xx,N,Q,a,b,c,d,e,K,M,A,B;

int main(){
    int T;cin>>T;
    while(T--){
        cin>>A>>B>>d;
        ll k=(A-1)+A*(B-1);
        ll j=(B-1)+B*(A-1);
        if(k>j)swap(j,k);
        // cerr<<j<<' '<<k<<'\n';
        if(k<=d&&d<=j){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}