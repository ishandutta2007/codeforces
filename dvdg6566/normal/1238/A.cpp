#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 1010000
#define MAXL 18
 
ll a,b,T;
 
int main(){
    cin>>T;
    while(T--){
        cin>>a>>b;
        if (a-b==1)cout<<"NO\n";
        else cout<<"YES\n";
    }
}