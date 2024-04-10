#include <iostream>

using namespace std;
int n, B, a[100], chet[100], nechet[100], A[100], c, b[100], k;
int ab(int val)
{
    if(val>=0)
        return val;
    else return -val;
}

int main()
{
    cin >> n >> B;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    if(a[0]%2==0)
            chet[0]++;
        else nechet[0]++;
    for(int i=1;i<n;i++)
    {
        chet[i]=chet[i-1];
        nechet[i]=nechet[i-1];
        if(a[i]%2==0)
            chet[i]++;
        else nechet[i]++;
        if(i<n-1 && chet[i]==nechet[i])
        {
            A[c]=ab(a[i]-a[i+1]);
            c++;
        }
    }
    for(int i=0;i<c;i++)
        b[A[i]]++;
    k=0;
    for(int i=0;i<100;i++)
        for(int j=0;j<b[i];j++)
        {
            A[k]=i;
            k++;
        }
    k=0;
    for(int i=0;i<c;i++)
    {
        if(A[i]<=B)
        {
            k++;
            B=B-A[i];
        }
    }
    cout << k;
    return 0;
}