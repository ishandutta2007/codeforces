#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int q[110], ar[n];
    char an[n];
    for(int a=0; a<110; a++) q[a]=0;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        q[ar[a]]++;
        an[a]='A';
    }
    int fi=0, se=0;
    for(int a=0; a<110; a++) if(q[a]==1) fi++;
    for(int a=0; a<110; a++)
    {
        if(q[a]==1 and fi-1>=se+1)
        {
            for(int b=0; b<n; b++) if(ar[b]==a) an[b]='B';
            fi--, se++;
        }
    }
    if(fi>se)
    {
        for(int a=0; a<n; a++)
        {
            if(q[ar[a]]>2)
            {
                an[a]='B', se++;
                break;
            }
        }
    }
    if(fi==se)
    {
        cout<<"YES\n";
        for(int a=0; a<n; a++) cout<<an[a];
    }
    else cout<<"NO";
}