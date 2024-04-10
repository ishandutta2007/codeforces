#include <iostream>

using namespace std;
int n, m, l, r, b[101], k;

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        {
            cin >> l >> r;
            for(int j=l;j<=r;j++)
                b[j]++;
        }
    for(int i=1;i<=m;i++)
        if(b[i]==0)
        k++;
    cout << k << endl;
    for(int i=1;i<=m;i++)
        if(b[i]==0)
        cout << i << ' ';
    return 0;
}