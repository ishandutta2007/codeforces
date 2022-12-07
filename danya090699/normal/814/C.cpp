#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n;
    int an[26][n+1];
    for(int a=0; a<26; a++) for(int b=0; b<=n; b++) an[a][b]=0;
    string s;
    cin>>s;
    for(int a=0; a<26; a++)
    {
        char sy='a'+a;
        for(int b=0; b<n; b++)
        {
            int yk=b;
            for(int c=1; c<=n; c++)
            {
                int us=0;
                while(yk<n)
                {
                    if(s[yk]==sy) yk++;
                    else
                    {
                        if(us==0)
                        {
                            yk++, us=1;
                        }
                        else break;
                    }
                }
                //cout<<yk<<" ";
                an[a][c]=max(an[a][c], yk-b);
            }
        }
    }
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int m;
        char sy;
        cin>>m>>sy;
        //cout<<m<<" ";
        cout<<an[sy-'a'][m]<<"\n";
    }
}