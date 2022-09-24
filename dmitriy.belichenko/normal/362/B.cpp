#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int n , m;

int main()
{
    cin >> n >> m;
    vector<int>a(m);
    if(m == 0)
   {
  cout << "YES" << "\n";
            return 0;
}

    for(int i = 0; i < m; i++)
    {
        cin >> a[i];
        if(a[i] == n)
        {
            cout << "NO" << "\n";
            return 0;

        }
    }
    sort(a.begin(), a.end());
    if(a[0] == 1 )
    {
        cout << "NO" << "\n";
        return 0;
        
    }
    for(int i = 0; i < m - 2 ; i++)
    {
        if(a[i+1] - a[i] == 1 && a[i+2] - a[i] == 2 || a[m - 1] == n)
        {
            cout << "NO" << "\n";
            return 0;
        }
        
    }
    cout << "YES" << "\n";
}