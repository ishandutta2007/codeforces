#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
int arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        bool isk=false;
        int lastloc=-100;
        bool iswork=false;
        if(n==1)iswork=true;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==k)isk=true;
            if(arr[i]>=k){
                if(lastloc>=i-2)iswork=true;
                lastloc=i;
            }
        }
        if(isk&&iswork)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}