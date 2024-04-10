#include <iostream>
using namespace std;
const int nmax=100;
struct fint
{
    int st,dr;
};
fint v[nmax+5];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i].st>>v[i].dr;
    int poz=0;
    while(poz<m)
    {
        bool ok=0;
        for(int i=1;i<=n;i++)
        {
            if(v[i].st<=poz and v[i].dr>poz)
            {
                ok=1;
                poz=v[i].dr;
            }
        }
        if(ok==0)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}