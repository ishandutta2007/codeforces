#include<bits/stdc++.h>
using namespace std;

int n,a[200005],c[35];

void mian(){
    cin>>n;
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<30;j++){
            c[j]+=a[i]>>j&1;
        }
    }
    int g=0;
    for(int i=0;i<30;i++)g=__gcd(g,c[i]);
    if(!*max_element(c,c+30)){
        for(int i=1;i<=n;i++)cout<<i<<' ';
        cout<<'\n';
    }else{
        for(int i=1;i<=g;i++)if(g%i==0)cout<<i<<' ';
        cout<<'\n';
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