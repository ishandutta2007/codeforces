#include <bits/stdc++.h>
#define pb push_back
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N=1e6+6;
int a[N];
long long s[N];
int main(){
    int n,mx=0; cin>>n;
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        s[a[i]-i+n]+=a[i],mx=max(mx,a[i]);
    }
    long long ans=0;
    for (int i=1;i<=mx+n;++i) ans=max(ans,s[i]);
    cout<<ans<<endl;
}