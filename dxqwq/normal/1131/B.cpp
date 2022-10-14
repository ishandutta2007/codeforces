#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,g=-1,a=0,b=0,c=0,d=0,e,f,ans=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&c,&d);
        e=max(a,b);
		f=min(c,d); 
        if(e>f) 
        { 
            a=c;
            b=d; 
        } 
		else if(g<e)
        {
            ans=ans+f-e+1;
            g=f;
        }
        else 
        {
            ans+=f-g;
            g=f;
        }
        a=c;
        b=d;
    }
    printf("%d",ans);
    return 0;
}