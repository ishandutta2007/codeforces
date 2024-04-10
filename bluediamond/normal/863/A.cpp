#include <iostream>
using namespace std;
int v[15];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,y=0,i,st,dr;
    cin>>n;
    while(n>0)
    {
        v[++y]=n%10;
        n/=10;
    }
    st=1;
    while(v[st]==0)
        st++;
    dr=y;
    while(st<=dr)
    {
        if(v[st]!=v[dr])
        {
            cout<<"NO";
            return 0;
        }
        st++;
        dr--;
    }
    cout<<"YES";
    return 0;
}