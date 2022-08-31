#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a=0,b=0;
    for(b=0;b<=(n/4)+1;b++){
        for(a=0;a<=(n/7)+1;a++)
            if(7*a+4*b==n)break;
            else if(7*a+4*b>n)break;
        if(7*a+4*b==n)break;
    }
    if(7*a+4*b==n){
    while(b-->0)cout<<4;
    while(a-->0)cout<<7;
    }
    else cout<< (-1);
}