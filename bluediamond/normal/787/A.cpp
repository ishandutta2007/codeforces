#include <iostream>
#include <algorithm>
using namespace std;
int v1[1005],v2[1005];
int main()
{
    ios_base::sync_with_stdio(false);
    int a,b,c,d,i;
    cin>>a>>b>>c>>d;
    for(i=0;i<=1000;i++)
        {
        v1[i]=b+a*i;
        v2[i]=d+c*i;
        }
    for(i=0;i<=1000;i++)
        if(binary_search(v2,v2+101,v1[i]))
        {
            cout<<v1[i];
            return 0;
        }
    cout<<-1;
    return 0;
}