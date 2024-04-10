#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1e5+5;

int a[maxn];
int n;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string g;
        cin>>n>>g;
        for(int i=1;i<=n;i++)a[i]=g[i-1]^'0';
        for(int i=1;i<=n;i++)a[i]+=a[i-1];
        map<int,int> st;
        long long ans=0;
        for(int i=0;i<=n;i++){
            ans+=st[a[i]-i];
            st[a[i]-i]++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}