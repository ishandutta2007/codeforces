#include <iostream>
#include <algorithm>
using namespace std;
int n;
char s[205];
int v[205],y=0,ap[30],rau[205];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    cin.get();
    cin.getline(s,205);
    for(int i=0;i<n;i++)
    {
        if('A'<=s[i] and s[i]<='Z')
            v[i+1]=-1;
        else
            v[i+1]=s[i]-'a';
    }
    v[0]=v[n+1]=-1;
    for(int i=0;i<=n+1;i++)
        if(v[i]==-1)
            rau[++y]=i;
    int best=0;
    for(int i=1;i<y;i++)
    {
        /**

        **/
        int st=rau[i]+1,dr=rau[i+1]-1;
        ///cout<<st<<" "<<dr<<"\n";
        for(int j=st;j<=dr;j++)
            ap[v[j]]=1;
        int dif=0;
        for(int j=0;j<26;j++)
        {
            dif+=ap[j];
            ap[j]=0;
        }
        best=max(best,dif);
    }
    cout<<best;
    return 0;
}
/**
12
zACaAbbaazzC
123456789012
**/