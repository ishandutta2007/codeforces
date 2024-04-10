#include <bits/stdc++.h>
using namespace std;
long long n,k,ans,z,now,last;
long long a[100005];
map<long long,int> kol;
int main(){
    cin>>n>>k;
    kol[0]=1;
    if (abs(k)!=1){
        z=1e16;
        while (z){
            ++now;
            z/=abs(k);
        }
    }
    for (int i=1;i<=n;++i){
        cin>>a[i];
        a[i]+=a[i-1];
        last=1;
        ++kol[a[i]];
        if (k==1){
            ans+=kol[a[i]-1];
            continue;
        } else if (k==-1){
            ans+=kol[a[i]-1];
            ans+=kol[a[i]+1];
            continue;
        }
        for (int j=1;j<=now+1;++j){
            long long x=a[i]-last;
            ans+=kol[x];
            last*=k;
        }
    }
    cout<<ans;
}