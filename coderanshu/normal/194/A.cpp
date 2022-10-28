#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n,k,i=1;
    cin>>n>>k;
    while(n*(++i)<=k){}
    if(i==3){
        cout<<n*(i)-k;return 0;
    }
    else cout<<0;
    
    return 0;
}