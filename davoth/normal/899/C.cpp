#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%4==0){
        cout<<0<<"\n"<<n/2<<' ';
        for(int i=1;i<n/2;i+=2){
            cout<<i<<' ';
        }
        for(int i=n;i>n/2;i-=2){
            cout<<i<<' ';
        }
    }else if(n%2==0){
        cout<<1<<"\n"<<n/2<<' ';
        for(int i=1;i<n/2+1;i+=2){
            cout<<i<<' ';
        }
        for(int i=n;i>n/2+1;i-=2){
            cout<<i<<' ';
        }
    }else if(n%4==3){
        cout<<0<<"\n"<<(n-3)/2+2<<' ';
        cout<<1<<' '<<n-1<<' ';
        for(int i=2;i<(n-2)/2+1;i+=2){
            cout<<i<<' ';
        }
        for(int i=n-2;i>(n-2)/2+1;i-=2){
            cout<<i<<' ';
        }
    }else{
        cout<<1<<"\n"<<n/2+1<<' '<<1<<' ';
        for(int i=2;i<n/2+1;i+=2){
            cout<<i<<' ';
        }
        for(int i=n;i>n/2+1;i-=2){
            cout<<i<<' ';
        }
    }
    return 0;
}