#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a[200005];
ll k;

void mian(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    while(k&&*min_element(a,a+n)){
        int d=*max_element(a,a+n);
        for(int i=0;i<n;i++)a[i]=d-a[i];
        k--;
    }
    if(k&1){
        int d=*max_element(a,a+n);
        for(int i=0;i<n;i++)a[i]=d-a[i];
    }
    for(int i=0;i<n;i++)cout<<a[i]<<' ';
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