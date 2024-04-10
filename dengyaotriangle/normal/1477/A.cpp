#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;long long k;
        cin>>n>>k;
        vector<long long> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        long long t=0;for(int i=1;i<n;i++)t=gcd(t,v[i]-v[i-1]);
        bool ok=0;
        for(int i=0;i<n;i++)if((k-v[i])%t==0)ok=1;
        cout<<(!ok?"NO\n":"YES\n");
    }
    return 0;
}