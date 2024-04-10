#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=5005;

int n,m;
int a[maxn];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        if(m==0){
            a[i]=n*(n+10)+i*n;
        }else if(m>=(i-1)/2){
            a[i]=i;
            m-=(i-1)/2;
        }else{
            a[i]=i+(i-1-m*2);
            m=0;
        }
    }
    if(m)cout<<-1;
    else for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    return 0;
}