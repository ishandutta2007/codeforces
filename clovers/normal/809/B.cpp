#include<bits/stdc++.h>
using namespace std;
void print(int x,int y)
{
    printf("1 %d %d\n",x,y);
    fflush(stdout);
}

int n,k,pos1;
char s[10];
void ask1(int L,int R,int flag)
{
    int l=L,r=R,best,mid;
    if(l==r) best=l;
    while(l<r)
    {
        int mid=(l+r)>>1;
        print(mid,mid+1);
        scanf("%s",s);
        if(s[0]=='T') //x closer
        {
            r=mid;
            best=mid;
        } 
        else l=mid+1,best=mid+1;
    }
    if(flag==1) pos1=best;
    else
    {
        if(best==pos1-1||best==pos1+1)
        {
            print(best,pos1);
            scanf("%s",s);
            if(s[0]=='T')
            {
                printf("2 %d %d\n",pos1,best);
                fflush(stdout);
                exit(0);
            }
        }
        else
        {
            printf("2 %d %d\n",pos1,best);
            fflush(stdout);
            exit(0);
        }
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    ask1(1,n,1);
    if(pos1!=n) ask1(pos1+1,n,2);
    if(pos1!=1) ask1(1,pos1-1,2);
    fflush(stdout);
    return 0;
}