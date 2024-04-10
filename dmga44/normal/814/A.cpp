#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;

int arr[205],b[205];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    for(int i=0;i<k;i++)
        cin >> b[i];

    sort(b,b+k);
    int p=k-1;
    for(int i=0;i<n;i++)
    {
        if(!arr[i])
        {
            arr[i]=b[p];
            p--;
        }
    }
    int res=true;
    for(int i=0;i<n-1 && res;i++)
        res&=(arr[i]<arr[i+1]);
    if(res)
        db("No")
    else
        db("Yes")
    return 0;
}