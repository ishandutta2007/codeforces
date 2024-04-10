#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;
int n;
int a[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        int ret=0;
        for(int i=n;i>=1;i--){
            int c=a[i];
            if(i!=n&&a[i]==a[i+1])continue;
            int ans=1;
            for(int j=i-1;j>=1&&a[j]==a[i];j--)ans++;
            while(1){
                int lb=max(a[i]+1,2*c-a[i]);
                int p=lower_bound(a+1,a+1+n,lb)-a;
                if(p>n)break;
                ans++;
                c=a[p];
            }
            ret=max(ret,ans);
        }
        cout<<n-ret<<'\n';
    }
    return 0;
}