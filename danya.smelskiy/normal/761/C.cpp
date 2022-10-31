#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[100];
long long b[100];
long long cc[100];
string s;
long long ans=10000000000;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        a[i]=10000;
        b[i]=10000;
        cc[i]=10000;
        cin>>s;
        for (int j=1;j<=m;++j){
            char c=s[j-1];
            long long len=j-1;
            len=min(len,m-j+1);
            if (c>='a' && c<='z') a[i]=min(a[i],len);
            if (c>='0' && c<='9') b[i]=min(b[i],len);
            if (c=='#' || c=='*' || c=='&') {  cc[i]=min(cc[i],len);}
        }
    }
 //   for (int i=1;i<=n;++i)
 //       cout<<a[i]<<" "<<b[i]<<" "<<cc[i]<<endl;
    for(int i=1;i<=n;++i){
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k)
        if (i!=j && j!=k && i!=k){
            ans=min(ans,a[i]+b[j]+cc[k]);
        }
    }
    cout<<ans;
}