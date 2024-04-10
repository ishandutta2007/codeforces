// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int ar[500005];
bool fin[500005];

bool chk(int n,int q){
    stack<int>z;
    rep(i,n){
        if(fin[ar[i]])return 0;
        while(z.size()&&z.top()>ar[i]){
            fin[z.top()]=1;
            z.pop();
        }
        if(z.size()&&z.top()==ar[i]);
        else z.push(ar[i]);
    }
    while(z.size()){
        fin[z.top()]=1;
        z.pop();
    }
    return fin[q];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,q;cin>>n>>q;
    rep(i,n){
        cin>>ar[i];}
    bool x=0;
    rep(i,n)if(ar[i]==q)x=1;
    if(!x)
    rep(i,n)if(ar[i]==0){
        ar[i]=q;
        break;
    }
    rep1(i,n-1)if(ar[i]==0)ar[i]=ar[i-1];
    for(int i=n-1;i>=0;i--)if(ar[i]==0)ar[i]=ar[i+1];
    rep(i,n)if(ar[i]==0)ar[i]=q;
    if(chk(n,q)){
        cout<<"YES\n";
        rep(i,n)cout<<ar[i]<<" \n"[i==n-1];
    }else cout<<"NO\n";
}