#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);gfdh
    int n;
    cin>>n;
    int ar[n], us[n], yk=0;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a], ar[a]--;
        us[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        int x, q=0;
        cin>>x;
        x--;
        if(us[x]) printf("0 ");
        else
        {
            while(ar[yk]!=x)
            {
                us[ar[yk]]=1, yk++, q++;
            }
            us[ar[yk]]=1, yk++, q++;
            cout<<q<<" ";
        }
    }
}