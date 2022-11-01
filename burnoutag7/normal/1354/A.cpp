#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll a,b,c,d;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d;
        a-=b;
        if(a<=0){
            cout<<b<<endl;
            continue;
        }
        if(c<=d){
            cout<<-1<<endl;
            continue;
        }
        cout<<b+(a+(c-d)-1)/(c-d)*c<<endl;
    }

    return 0;
}