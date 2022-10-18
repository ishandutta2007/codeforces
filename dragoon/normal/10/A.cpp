#include<stdio.h>
#include<utility>
#include<vector>
using namespace std;

int n,P1,P2,T1,T2,P3,L,R,ans=0,old,i;

int f(int a, int b)
{
    if(b-a<=T1) return (b-a)*P1;
    int ret = T1*P1;
    if(b-a-T1<=T2) return ret + (b-a-T1)*P2;
    ret += T2*P2;
    return ret + (b-a-T1-T2)*P3;
}

int main()
{

    scanf("%d%d%d%d%d%d",&n,&P1,&P2,&P3,&T1,&T2);
    scanf("%d%d",&L,&R);

    ans += (R-L)*P1;
    old = R;

    for(i=1;i<n;i++)
    {
        scanf("%d%d",&L,&R);

        ans += f(old, L);
        ans += (R-L)*P1;

        old = R;
    }

    printf("%d\n",ans);

    return 0;
}