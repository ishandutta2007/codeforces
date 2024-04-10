#include<bits/stdc++.h>
using namespace std;

int n,a[100005],m,b[100005],c[100005],l[100005],r[100005],ans,pw,pb;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]!=b[m])b[++m]=a[i];
        else c[m]=1;
    }
    swap(a,b);
    swap(n,m);
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    for(int i=1;i<=n;i++)if(c[i])l[i]=a[i];
    else l[i]=l[i-1];
    for(int i=n;i>=1;i--)if(c[i])r[i]=a[i];
    else r[i]=r[i+1];
    for(int i=1;i<=n;i++)if(c[i]){
        ans+=pw!=a[i];
        ans+=pb!=a[i];
        pw=pb=a[i];
    }else{
        if(pw!=a[i]&&pb!=a[i]){
            ans++;
            if(pw==r[i]){
                pw=a[i];
            }else pb=a[i];
        }else if(pw!=a[i]){
            ans++;
            pw=a[i];
        }else if(pb!=a[i]){
            ans++;
            pb=a[i];
        }else assert(false);
    }
    cout<<ans<<endl;

    return 0;
}