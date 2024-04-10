#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> b(n);
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++)
    {
        vector<int> a(n);
        a[i]=b[i];
        for(int j=(i+1)%n;j!=i;j=(j+1)%n) a[j]=(a[(j-1+n)%n]+i)%n;
        for(int j=0;j<n;j++) cout << a[j] << " \n"[j==n-1];
    }
    return 0;
}