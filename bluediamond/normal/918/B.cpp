#include <iostream>
using namespace std;
const int nmax=1000;
struct data
{
    string name,ip;
};
int n,m;
data v[nmax+5];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i].name>>v[i].ip;
    for(int i=1;i<=m;i++)
    {
        string name,server;
        cin>>name>>server;
        server.pop_back();
        int poz;
        for(int j=1;j<=n;j++)
            if(server==v[j].ip)
                poz=j;
        cout<<name<<" "<<server<<"; #"<<v[poz].name<<"\n";
    }
    return 0;
}