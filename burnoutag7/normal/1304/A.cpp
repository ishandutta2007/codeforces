#include<bits/stdc++.h>
using namespace std;

int t,x,y,a,b;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>x>>y>>a>>b;
        if((y-x)%(a+b)){
            cout<<-1<<endl;
        }else{
            cout<<(y-x)/(a+b)<<endl;
        }
    }

    return 0;
}