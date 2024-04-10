//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, c=0, an=0;
    cin>>n>>a>>b;
    for(int i=0; i<n; i++)
    {
        int q;
        cin>>q;
        if(q==1)
        {
            if(a>0) a--;
            else
            {
                if(b>0)
                {
                    b--, c++;
                }
                else
                {
                    if(c>0) c--;
                    else an++;
                }
            }
        }
        else
        {
            if(b>0) b--;
            else an+=2;
        }
    }
    cout<<an;
}