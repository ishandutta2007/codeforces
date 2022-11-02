#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[1005];

void mian(){
    cin>>n>>m;
    a[n+1]=a[0]='0';
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt+=a[i]=='1';
    }
    int cur=-1;
    while(cnt!=cur&&m--){
        for(int i=1;i<=n;i++){
            if(a[i]=='0'&&((a[i-1]=='1')^(a[i+1]=='1')))a[i]='2';
        }
        cnt=cur;
        cur=0;
        for(int i=1;i<=n;i++){
            if(a[i]=='2')a[i]='1';
            cur+=a[i]=='1';
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i];
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