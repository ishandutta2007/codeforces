#include <bits/stdc++.h>
using namespace std;
long long n,k,last,ttime,x,y,a[100001];
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;++i){
        cin>>x>>y;
        a[x]=max(a[x],y);
    }
    last=k;
    for (int i=k;i>0;--i)
    if (a[i]>0){
        ttime+=last-i;
        if (ttime<a[i]) ttime+=a[i]-ttime;
        last=i;
    }
    ttime+=last;
    cout<<ttime;
}