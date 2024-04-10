#include <iostream>
#include <algorithm>
using namespace std;
int n,a,b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);



    char ch;
    cin>>n;
    cin.get();
    for(int i=1;i<=n;i++)
    {
        ch=cin.get();
        if(ch=='1')
            a++;
        else
            b++;
    }
    cout<<n-2*min(a,b);
    return 0;
}