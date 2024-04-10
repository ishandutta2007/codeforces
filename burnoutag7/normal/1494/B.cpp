#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,a[4];
    cin>>n>>a[0]>>a[1]>>a[2]>>a[3];
    for(int s=0;s<1<<4;s++){
        bool f=true;
        for(int i=0;i<4;i++){
            f&=a[i]>=(s>>i&1)+(s>>(i+1&3)&1)&&a[i]-(s>>i&1)-(s>>(i+1&3)&1)<=n-2;
        }
        if(f){
            cout<<"yEs\n";
            return;
        }
    }
    cout<<"nO\n";
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