#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a[100005];

void mian(){
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int mx=*max_element(a+1,a+1+n);
    cout<<mx+(double)(sum-mx)/(n-1)<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout<<fixed<<setprecision(9);
    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}