//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e3;
char sm[sz][sz];
void re(int u, int v)
{
    sm[u][v]='Y', sm[v][u]='Y';
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, fo=0, q=2;
    cin>>n;
    for(int a=0; a<sz; a++) for(int b=0; b<sz; b++) sm[a][b]='N';
    vector <int> po(1);
    po[0]=1;
    for(int a=29; a>=0; a--)
    {
        if(n/(1<<a)==1)
        {
            if(fo!=0)
            {
                int pr=po[a], le=(fo-a)*2;
                for(int b=0; b<le-1; b++)
                {
                    re(pr, q), pr=q, q++;
                }
                re(pr, 0);
            }
            else
            {
                if(a==0) re(0, 1);
                else
                {
                    for(int b=0; b<a-1; b++)
                    {
                        re(q-1, q);
                        re(q-1, q+1);
                        re(q, q+2);
                        re(q+2, q+1);
                        q+=3, po.push_back(q-1);
                    }
                    re(q, q-1);
                    re(q-1, q+1);
                    re(0, q);
                    re(0, q+1);
                    q+=2;
                    fo=a;
                }
            }
            n-=(1<<a);
        }
    }
    cout<<q<<"\n";
    for(int a=0; a<q; a++)
    {
        for(int b=0; b<q; b++) cout<<sm[a][b];
        cout<<"\n";
    }
}