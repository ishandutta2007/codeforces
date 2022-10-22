#include <bits/stdc++.h>
using namespace std;
const int si=1e5+10;
int main()
{
    int n;
    cin >> n;
    int a[si];
    a[0]=2;
    int i=1;
    for(int j=0; j<n; j++){
        int temp;
        cin >> temp;
        if(temp%2==a[i-1]) i--;
        else{
            a[i]=temp%2;
            i++;
        }
    }
    if(i<=2) cout << "YES";
    else cout << "NO";
    return 0;
}