#include<bits/stdc++.h>
using namespace std;

int q;
long long k,n,a,b;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>k>>n>>a>>b;
        k--;
        if(n*b>k){
            cout<<-1<<endl;
        }else{
            k-=n*b;
            cout<<min(k/(a-b),n)<<endl;
        }
    }

    return 0;
}