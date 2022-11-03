#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int n,k;
int a[111111];
bool b[111111];

int binSearch(int x)
{
    int l=0,r=n-1;
    while (l<=r)
    {
        int m = (l+r)/2;
        if (a[m]==x)return m;
        if (a[m]>x)
            r = m-1;
        else
            l = m+1;
    }
    return -1;
}

int main()
{
    cin >> n >> k;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
        b[i] = true;
    }
    sort(a, a+n);
    int ans = 0;
    for (int i=n-1; i>=0; i--)
        if (b[i])
        {
            ans++;
            if (a[i]%k==0)
            {
                int j = binSearch(a[i]/k);
                if (j!=-1)b[j]=false;
            }
        }
    cout << ans << endl;
    return 0;
}