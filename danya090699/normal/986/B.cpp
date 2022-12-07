#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], us[n], cy=0;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]), ar[a]--;
        us[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            int v=a;
            while(us[v]==0)
            {
                us[v]=1, v=ar[v];
            }
            cy^=1;
        }
    }
    int st=n%2, add=(3*n)%2;
    if((st+add)%2!=cy) cout<<"Um_nik";
    else cout<<"Petr";
}