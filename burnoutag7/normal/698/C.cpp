#include<bits/stdc++.h>
using namespace std;

int n,k;
double p[20],f[1<<20],a[20];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>p[i];
    int c=0;
    for(int i=0;i<n;i++)c+=p[i]>0;
    if(c<k){
        for(int i=0;i<n;i++)cout<<(p[i]>0)<<' ';
        return 0;
    }
    f[0]=1;
    for(int s=0;s<1<<n;s++){
        double sp=0;
        for(int i=0;i<n;i++)if(s>>i&1^1)sp+=p[i];
        for(int i=0;i<n;i++)if(s>>i&1^1)f[s|1<<i]+=f[s]*p[i]/sp;
        else if(__builtin_popcount(s)==k)a[i]+=f[s];
    }
    cout<<fixed<<setprecision(10);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }

    return 0;
}