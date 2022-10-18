#include<bits/stdc++.h>

using namespace std;

const int maxn=305;

int n;
long long a[maxn];

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+1+n);
        long long ans=-1;
        bool ok=1;
        for(int i=1;i<=(n+1)/2;i++){
            long long cx=a[i]*a[n-i+1];
            if(ans==-1){
                ans=cx;
            }else{
                if(ans!=cx) ok=0;
            }
        }
        int cnt=0;
        for(long long i=2;i*i<=ans;i++){
            if(ans%i==0){
                long long c1=i,c2=ans/i;
                if(c1!=c2) cnt++;
                cnt++;
            }
        }
        if(cnt!=n) ok=0;
        cout<<(ok?ans:-1)<<'\n';
    }
    return 0;
}