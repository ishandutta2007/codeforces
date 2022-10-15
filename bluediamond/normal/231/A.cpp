#include <iostream>
using namespace std;
int main()
{
    int n,i,a,b,c,s=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        if(a+b+c>=2)
            s++;
    }
    cout<<s;
    return 0;
}