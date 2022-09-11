#include<stdio.h>
#include<iostream>
#include<set>
#define M 10000000
using namespace std;
bool used[20000000];
main(){
    long long n,m,an=0,i,j,x;
    cin>>n>>m;
    for(i=1;i<=n&&i*i<=m;i++)an+=i*i*2-1;
    an+=(n-i+1)*m*2;
    for(i=1;i<=n;i++){
        for(j=i-1;j>=0;j--){
            x=i*i-j*j;
            if(x<=m){
                if(used[-i-j+M])an--;
                else used[M-i-j]=1;
                if(j){
                    if(used[M-i+j])an--;
                    else used[M-i+j];
                }
            }
            else break;
        }
    }
    cout<<an<<endl;
}