#include <bits/stdc++.h>
using namespace std;
int a[10003];
bool b=0;
int main()
{
	int n,m,k,x,l,i;
    scanf("%d%d",&n,&m);
    for(i=1; i<=m; i++)
    {
        cin>>k;
        memset(a,0,sizeof(int)*10010);
        b=false;
        for(int j=1; j<=k; j++)
        {
            cin>>x;
            if(a[abs(x)]==-x) b=true;
            a[abs(x)]=x;
        }
        if(!b) break;
    }
    if(i>m)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}