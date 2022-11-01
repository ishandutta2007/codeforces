#include<bits/stdc++.h>
using namespace std;

int f,b;

int main(){

    cout<<"? ";
    for(int i=0;i<100;i++){
        cout<<i<<' ';
    }
    cout<<endl;

    cin>>f;
    if(f==-1)return 0;
    f=((f>>7)<<7);

    cout<<"? ";
    for(int i=(1<<7);i<=(100<<7);i+=(1<<7)){
        cout<<i<<' ';
    }
    cout<<endl;

    cin>>b;
    if(b==-1)return 0;
    b=(b&((1<<7)-1));

    cout<<"! "<<(f|b)<<endl;

    return 0;
}