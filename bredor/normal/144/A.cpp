//  228

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    int arr[x],ma=0,mi=101,maxi,mini;
    for(int i=0 ; i<x ; i++)
    {
        cin>>arr[i];
        if(arr[i]>ma)
        {
            ma = arr[i];
            maxi = i;
        }
        if(arr[i]<=mi)
        {
            mi = arr[i];
            mini = i;
        }
    }
    if(maxi>mini)
    {
        mini++;
    }
    cout<<maxi + (x-1) - mini;
    return 0;

}