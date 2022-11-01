#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto query=[](int l,int r)->int
    {
        cout << "? " << l << " " << r << "\n";
        cout.flush();
        int a;
        cin >> a;
        return a;
    };
    int sum=query(1,n);
    vector<int> a(n+1,0);
    a[1]=sum-query(2,n);
    for(int i=2;i<=n-1;i++) a[i]=query(i-1,i)-a[i-1];
    int s=0;
    for(int i=1;i<=n-1;i++) s+=a[i];
    a[n]=sum-s;
    cout << "! ";
    for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
    cout.flush();
    return 0;
}