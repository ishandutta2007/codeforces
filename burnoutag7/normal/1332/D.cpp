#include<bits/stdc++.h>
using namespace std;

int k,mb;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>k;
    for(int i=0;i<31;i++)if(k>>i&1)mb=i;
    cout<<"3 2"<<endl;
    cout<<(1<<(mb+2))-1<<' '<<k<<endl;
    cout<<(1<<(mb+1))<<' '<<(k|(1<<(mb+1)))<<endl;
    cout<<0<<' '<<k<<endl;

    return 0;
}