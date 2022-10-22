#include <iostream>

using namespace std;
int n, c, k;
char a[100000], b[100000];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];
    k=0;
    for(int i=0;i<n/2;i++)
    {
        c=n-i-1;
        if(!((a[i]==a[c] && b[i]==b[c])||(a[i]==b[i] && a[c]==b[c])||(a[i]==b[c] && a[c]==b[i])))
            if(a[i]==b[i] || a[c]==b[c] || a[i]==b[c] || a[c]==b[i] || b[i]==b[c])
            k++;
        else k=k+2;
    }
    if(n%2==1 && a[n/2]!=b[n/2])
        k++;
    cout << k;
    return 0;
}