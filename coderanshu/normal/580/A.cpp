#include <iostream>
#include<vector>

using namespace std;

int main()
{
    vector<long int> arr;
    long int n,i,j,k=0,maxm=1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>j;
        arr.push_back(j);

    }

    for(i=0;i<arr.size()-1;i++)
    {
       if(arr[i]>arr[i+1])
       {
           maxm=max(k+1,maxm);
        k=0;
       }
       else k++;
    }
    if(k!=0)
        cout<<max(maxm,k+1);
    else
    cout<<maxm;

    return 0;
}