#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

long long t;
int n;
long long a[maxn];

int main(){
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=0;
    while(1){
        long long c1=0,g1=0;
        for(int i=1;i<=n;i++){
            if(a[i]<=t){
                t-=a[i];
                c1++;
                ans++;
                g1+=a[i];
            }
        }
        if(c1==0) break;
        ans+=c1*(t/g1);
        t=t%g1;
    }
    cout<<ans;
    return 0;
}