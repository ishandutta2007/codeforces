#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, gq=0,yk=0, an=0;
    string s;
    cin>>n>>s;
    for(int a=0; a<n; a++) if(s[a]=='G') gq++;
    int sq=0, cg=0;
    for(int a=0; a<n; a++)
    {
        while(yk<n)
        {
            if(s[yk]=='S')
            {
                if(sq) break;
                else sq++, yk++;
            }
            else cg++, yk++;
        }
        an=max(an, min(cg+1, gq));
        if(s[a]=='S') sq--;
        else cg--;
    }
    cout<<an;
}