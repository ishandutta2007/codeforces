#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=20005;

int main(){
    int t;
    cin>>t;
    int c=0;
    while(t--){
        int n;
        cin>>n;
        if(n%2==0)cout<<n/2<<'\n';
        else{
            int f1=floor((double)(n)/2),f2=ceil((double)(n)/2);
            if(c)cout<<f1<<'\n';
            else cout<<f2<<'\n';
            c=!c;
        }
    }
    return 0;
}