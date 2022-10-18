#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200;

char x[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>x;
        int sm=0;
        bool i0=0;
        int i2=0;
        for(int i=0;i<strlen(x);i++){
            sm+=x[i]^'0';
            if(x[i]=='0')i0=1;
            if((x[i]&1)==0)i2++;
        }
        if(i0&&i2>=2&&sm%3==0)cout<<"red\n";
        else cout<<"cyan\n";

    }    
    return 0;
}