#include<bits/stdc++.h>
using namespace std;

int n,m,cnt;
int a[1500];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<i;j++){
            cnt+=a[j]>a[i];
        }
    }
    cnt&=1;
    cin>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        cnt^=((b-a+1)>>1)&1;//   
        cout<<((cnt&1)?"odd":"even")<<endl;
    }

    return 0;
}