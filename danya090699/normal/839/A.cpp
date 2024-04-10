//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, q=0, an;
    cin>>n>>k;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        q+=x;
        k-=min(q, 8);
        q-=min(q, 8);
        if(k<=0)
        {
            an=a+1;
            break;
        }
    }
    if(k>0) cout<<-1;
    else cout<<an;
}