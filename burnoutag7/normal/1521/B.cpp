#include<bits/stdc++.h>
using namespace std;

int n,a[100005];

void mian(){
    cin>>n;
    int p;
    for(int i=1;i<=n;i++)cin>>a[i];
    p=min_element(a+1,a+1+n)-a;
    cout<<n-1<<'\n';
    for(int i=1;i<=n;i++)if(i!=p){
        if(i&1^p&1)cout<<i<<' '<<p<<' '<<a[p]+1<<' '<<a[p]<<'\n';
        else cout<<i<<' '<<p<<' '<<a[p]<<' '<<a[p]<<'\n';
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}