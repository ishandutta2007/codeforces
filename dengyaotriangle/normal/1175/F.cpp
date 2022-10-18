#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=300005;

int n;
unsigned long long hs[maxn],pfx[maxn],afx[maxn];
int a[maxn];
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
auto rnd=std::bind(uniform_int_distribution<unsigned long long>(0,-1ull),rng);

inline int calc(){
    int ans=0;
    for(int i=1;i<=n;i++){afx[i]=afx[i-1]^hs[a[i]];}
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            int mx=1;
            for(int j=i;j<=n;j++){
                mx=max(mx,a[j]);
                //cerr<<j<<':'<<mx<<endl;
                if(j-mx+1>=1&&((afx[j]^afx[j-mx])==pfx[mx])){
                
                    ans++;
                }
                if(a[j+1]==1)break;
            }
        }
    }return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){hs[i]=rnd();}
    for(int i=1;i<=n;i++){pfx[i]=pfx[i-1]^hs[i];}
    for(int i=1;i<=n;i++){cin>>a[i];ans-=a[i]==1;}
    ans+=calc();
    reverse(a+1,a+1+n);
    ans+=calc();
    cout<<ans;
    return 0;
}