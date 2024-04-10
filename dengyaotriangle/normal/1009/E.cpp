#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1000006;
const int mdn=998244353;
const int inv2=(mdn+1)/2;

int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    int pw=1;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=(a[i]*(long long)pw+a[i-1])%mdn;
        pw=pw*(long long)inv2%mdn;
        if(i==n)ans=(ans+a[i])%mdn;
        else ans=(ans+a[i]*(long long)inv2)%mdn;
    }
    for(int i=1;i<n;i++)ans=ans*2%mdn;
    cout<<ans;
    return 0;
}