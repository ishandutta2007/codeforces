#include <bits/stdc++.h>
using namespace std;
int n;
bool perfect(int key)
{
    int ans=0;
    while(key>0)
    {
        ans+=key%10;
        if(ans>10)
            return 0;
        key/=10;
    }
    if(ans==10)
        return 1;
    return 0;
}
int main()
{
    cin>>n;
    int i=1,nr=0;
    while(nr<n)
    {
        i++;
        nr+=perfect(i);
    }
    cout<<i;
    return 0;
}
/**

**/