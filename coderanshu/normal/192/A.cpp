#include<bits/stdc++.h>
using namespace std;
// nice concept of 2d array
long int tri(long int x)
{
    return (x*(x+1))/2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    long int n,i=1,j=1;
    cin>>n;
    while(tri(i)<n)
    {
        j=sqrt((n-tri(i))*2);
        while(tri(i)+tri(j)<n)
        j++;
        if(tri(i)+tri(j)==n)
        {
            cout<<"YES";return 0;
        }
        i++;
    }
    cout<<"NO";
    return 0;
}