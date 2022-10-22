#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long sum=0,a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum+=a[i];
    }
    for(int i=0; i<n; i++){
        if(sum-a[i]<a[i]){
            cout << "NO";
            return 0;
        }
    }
    if(sum%2==0) cout << "YES";
    else cout << "NO";
    return 0;
}