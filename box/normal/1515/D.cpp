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

int L[200005],R[200005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,l,r;cin>>n>>l>>r;
        rep1(i,n)L[i]=R[i]=0;
        rep1(i,l){
            int v;cin>>v;
            L[v]++;
        }
        rep1(i,r){
            int v;cin>>v;
            R[v]++;
        }
        int mo=0,A=0,B=0;
        rep1(i,n){
            int x=min(L[i],R[i]);
            L[i]-=x;R[i]-=x;
            A+=L[i];B+=R[i];
        }
        if(A<B){swap(A,B);rep1(i,n)swap(L[i],R[i]);}
        rep1(i,n){
            while(L[i]>=2&&A-2>=B){
                L[i]-=2;A-=2;mo++;
            }
        }
        mo+=(A-B)/2+(A+B)/2;
        cout<<mo<<endl;
    }
}