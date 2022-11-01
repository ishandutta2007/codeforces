#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,k,pt;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(pt=1;pt*(pt+1)/2<k;pt++);
    while(k+(n-pt)<pt*(pt+1)/2)pt--;
    while(k+(n-pt)>pt*(pt+1)/2)pt++;
    cout<<n-pt<<endl;

    return 0;
}