#include<bits/stdc++.h>
using namespace std;
int two[32];
void db()
{
    two[0]=1;
    for(int i=1;i<32;i++)
        two[i]=two[i-1]*2;
}
int main()
{
    db();
    int n;
    int ans=1;
    cin>>n;
    int tar=n;
    int maxn=0;
    int nnn=0;
    int tot=0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)
            {
                n/=i;
                cnt++;
            }
            ans*=i;
            tot++;
            if(maxn==cnt) nnn++;
            else if(maxn<cnt) nnn=1;
            maxn=max(maxn,cnt);
        }
    }
    ans*=n;
    if(n>1) tot++,nnn=1;
    int ans2=0;
    for(int i=0;i<32;i++)
    {
        if(two[i]>=maxn)
        {
            ans2=i;break;
        }
    }
    //cout<<tot<<endl;
    //cout<<nnn<<endl;
    if(two[ans2]>maxn||tot!=nnn) ans2++;
    if(ans==tar) ans2=0;
    printf("%d %d\n",ans,ans2);

}