#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int b=0;
        while((1<<(b+1))<=n-1) b++;
        for(int i=1;i<n;i++) if((i&(1<<b))==0) cout << i << " ";
        cout << "0 " << (1<<b) << " ";
        for(int i=0;i<n;i++) if((i&(1<<b))&&i!=(1<<b)) cout << i << " ";
        cout << "\n";
    }
    return 0;
}