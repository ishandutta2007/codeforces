#include<bits/stdc++.h>
using namespace std;

int q,n,m,t;
int c[2];
long long cnt;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>n;
        c[0]=c[1]=cnt=0;
        while(n--){
            cin>>t;
            c[t&1]++;
        }
        cin>>m;
        while(m--){
            cin>>t;
            cnt+=c[t&1];
        }
        cout<<cnt<<endl;
    }

    return 0;
}