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
        if(n==3)
        {
            cout << "1 3 2\n";
            cout << "3 1 2\n";
            cout << "3 2 1\n";
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                int a=1;
                vector<int> p(n,0);
                for(int j=i;a<=n;j=(j+1)%n) p[j]=(a++);
                swap(p[(i+1)%n],p[(i+2)%n]);
                for(int j=0;j<n;j++) cout << p[j] << " \n"[j==n-1];
            }
        }
    }
    return 0;
}