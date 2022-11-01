#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    int l=0,r=n-1,a=0,b=0;
    while(l<=r)
    {
        if(a==b||a<b)
        {
            a+=arr[l];
            l++;
        }
        else
        {
            b+=arr[r];
            r--;
        }
    }
    cout << l << " " << n-l << endl;
    return 0;
}