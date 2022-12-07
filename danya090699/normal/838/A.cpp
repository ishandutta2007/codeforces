//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10;
int ma[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=1e9;
    cin>>n>>m;
    for(int a=0; a<=max(n, m)*2; a++) for(int b=0; b<=max(n, m)*2; b++) ma[a][b]=0;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        for(int b=0; b<m; b++) if(s[b]=='1') ma[a+1][b+1]=1;
    }
    for(int a=1; a<=max(n, m)*2; a++)
    {
        for(int b=1; b<=max(n, m)*2; b++)
        {
            ma[a][b]+=ma[a][b-1]+ma[a-1][b]-ma[a-1][b-1];
        }
    }
    for(int k=2; k<=max(n, m); k++)
    {
        int cu=0;
        for(int a=k; a-k<n; a+=k)
        {
            for(int b=k; b-k<m; b+=k)
            {
                int q1=ma[a][b]-ma[a][b-k]-ma[a-k][b]+ma[a-k][b-k];
                cu+=min(q1, k*k-q1);
            }
        }
        an=min(cu, an);
    }
    cout<<an;
}