#include <iostream>
using namespace std;
string v[105];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        bool ok=1;
        for(int j=0;j<i;j++)
            if(v[i]==v[j])
            {
                ok=0;
                break;
            }
        if(!ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}