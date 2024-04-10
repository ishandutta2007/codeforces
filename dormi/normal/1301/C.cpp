#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        lli n,m;
        cin>>n>>m;
        if(m==0){
            printf("0\n");
            continue;
        }
        lli tot=n*(n+1)/2;
        lli normgap=(n-m)/(m+1);
        lli othgapam=n-m-(m+1)*normgap;
        printf("%lli\n",tot-normgap*(normgap+1)/2*(m+1-othgapam)-(normgap+1)*(normgap+2)/2*(othgapam));
    }
    return 0;
}