#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    while(b){
        a=a%b;
        swap(a,b);
    }
    return a;
}

int n,a[2005],m,ans;

void mian(){
    cin>>n;
    m=ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]&1)a[++m]=a[i];
    }
    ans=(n-m)*m+(n-m-1)*(n-m)/2;
    for(int i=1;i<m;i++)for(int j=i+1;j<=m;j++)ans+=gcd(a[i],a[j])>1;
    cout<<ans<<'\n';
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