#include<bits/stdc++.h>
using namespace std;

int n,a[105],b[105];

void mian(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int l=0,r=n;
    b[0]=-1;
    for(int i=0;i<n;i++)if(b[l]==a[i])b[r--]=a[i];
    else b[++l]=a[i];
    for(int i=1;i<=n;i++)cout<<b[i]<<' ';
    cout<<'\n';
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