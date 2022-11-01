#include<bits/stdc++.h>
using namespace std;

int n,a[200005];

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int p=0,c=0,mx=*max_element(a+1,a+1+n);
    for(int i=n;i>=1;i--){
        if(a[i]==mx)break;
        if(a[i]>p){
            c++;
            p=a[i];
        }
    }
    cout<<c<<'\n';
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