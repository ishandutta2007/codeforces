#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,sum1=0,sum2=0;
    cin >> n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin >> ar[i];
    }
    sort(ar,ar+n);
    for(int i=0;i<(n/2);i++){
        sum1+=ar[i];
        sum2+=ar[n-1-i];
    }
    if(n%2!=0)
    {
        sum2+=ar[n/2];
    }
    cout << sum2*sum2 + sum1*sum1;
    return 0;
}