#include <iostream>

using namespace std;
int n, k, a[100], b[101], k1, c[100];

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(b[a[i]]==0)
        {
            c[k1]=i+1;
            b[a[i]]++;
            k1++;
        }
    }
    if(k1<k)
        cout << "NO";
    else
    {
        cout << "YES" << endl;
        for(int i=0;i<k;i++)
            cout << c[i] << ' ';
    }
    return 0;
}