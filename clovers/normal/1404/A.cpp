#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
int TTT=1,n,a[N],k;

void init()
{

}

char s[N];
void solve()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    for(int i=1;i<=k;i++)
    {
        int tmp=-1;
        for(int j=i;j<=n;j+=k)
        {
            if(s[j]!='?')
            {
                if(tmp==-1) tmp=s[j]-'0';
                else if(tmp!=s[j]-'0') 
                {
                    puts("NO");
                    return;
                }
            } 
        } 
        a[i]=tmp;
    }
    int sum1=0,sum2=0;
    for(int i=1;i<=k;i++) 
    {
        if(a[i]==0) sum1++;
        else if(a[i]==1) sum2++;
    }
    if(sum1>k/2||sum2>k/2) puts("NO");
    else puts("YES");
}

int main()
{
    scanf("%d",&TTT);
    while(TTT--){init(); solve();}
    return 0;
}