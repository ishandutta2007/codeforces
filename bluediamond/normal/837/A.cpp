#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,i,sum=0,mi=0;
    char ch;
    cin>>n;
    cin.get();
    for(i=1;i<=n;i++)
    {
        ch=cin.get();
        if('A'<=ch and ch<='Z')
            sum++;
        if(ch==' ' or  i==n)
        {
            mi=max(mi,sum);
            sum=0;
            continue;
        }
    }
    cout<<mi;
    return 0;
}