#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    bool an[n-k+1];
    for(int a=0; a<(n-k+1); a++)
    {
        string s;
        cin>>s;
        if(s=="YES") an[a]=1;
        else an[a]=0;
    }
    char ar[n][2];
    for(int a=0; a<k-1; a++)
    {
        ar[a][0]='A'+a/20;
        ar[a][1]='a'+a%20;
    }
    for(int a=k-1; a<n; a++)
    {
        bool cu=an[a-(k-1)];
        if(cu)
        {
            ar[a][0]='A'+a/20;
            ar[a][1]='a'+a%20;
        }
        else
        {
            ar[a][0]=ar[a-(k-1)][0];
            ar[a][1]=ar[a-(k-1)][1];
        }
    }
    for(int a=0; a<n; a++) cout<<ar[a][0]<<ar[a][1]<<" ";
}