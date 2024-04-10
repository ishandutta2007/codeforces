#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
ll evenpsa[MAXN],oddpsa[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a;
        for(int i=0;i<n;i++){
            cin>>a;
            if(i)evenpsa[i]=evenpsa[i-1],oddpsa[i]=oddpsa[i-1];
            if(i%2)oddpsa[i]+=a;
            else evenpsa[i]+=a;
        }
        ll bestloc[2]={0,0};
        ll best=0;
        for(int i=0;i<n;i++){
            best=max(best,bestloc[i%2]+oddpsa[i]+evenpsa[n-1]-evenpsa[i]);
            bestloc[i%2]=max(bestloc[i%2],evenpsa[i]-oddpsa[i]);
        }
        best=max(best,evenpsa[n-1]);
        printf("%lli\n",best);
        for(int i=0;i<n;i++)evenpsa[i]=0,oddpsa[i]=0;
    }
    return 0;
}