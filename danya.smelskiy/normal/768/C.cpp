#include <bits/stdc++.h>
using namespace std;
long long n,k,x,ansx,ansy;
long long z1,z2;
long long a[100005],b[100005];
int main(){
    cin>>n>>k>>x;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    ansx=-1;
    ansy=-1;
    for (int i=1;i<=k;++i){
        z1=b[1];
        z2=b[n];
        for (int j=1;j<=n;++j){
            b[j]=a[j];
            if (j%2==1) a[j]=a[j]^x;
        }
        sort(a+1,a+n+1);
        if (a[1]==z1 && a[n]==z2 && a[n]==b[n] && a[1]==b[1]) {
            if ((k-i-1)%2==0) {
                ansx=a[1];
                ansy=a[n];
            } else {
                ansx=b[1];
                ansy=b[n];
            }
            break;
        }
    }
    if (ansx==-1){
        ansx=a[1];
        ansy=a[n];
    }
    cout<<ansy<<" "<<ansx;
}