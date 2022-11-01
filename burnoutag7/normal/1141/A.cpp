#include<bits/stdc++.h>
using namespace std;

int n,m,a;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    if(m%n){
        cout<<-1<<endl;
        return 0;
    }
    m/=n;
    while(m%2==0&&m!=0){
        m/=2;
        a++;
    }
    while(m%3==0&&m!=0){
        m/=3;
        a++;
    }
    if(m!=1){
        cout<<-1<<endl;
        return 0;
    }
    cout<<a<<endl;
    
    return 0;
}