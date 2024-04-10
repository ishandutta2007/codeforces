#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s,t;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cin >> t;
        cnt+=(s!=t);
        s=t;
    }
    cout << cnt << endl;
    return 0;
}