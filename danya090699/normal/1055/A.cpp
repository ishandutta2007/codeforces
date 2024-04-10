#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, s, ok=0;
    cin>>n>>s;
    s--;
    bool fi[2][n];
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n; a++) cin>>fi[i][a];
    }
    if(fi[0][0])
    {
        if(fi[0][s]) ok=1;
        else
        {
            if(fi[1][s])
            {
                for(int a=s+1; a<n; a++) if(fi[0][a] and fi[1][a]) ok=1;
            }
        }
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
}