#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int t;
    int p[40];
    for(int i=0;i<n;i++)
    {
        cout<<1<<endl;
        cin>>t;
        if(t==0)
            return 0;
        else if(t==1)//t>1
            p[i]=1;
        else p[i]=0;
    }
    int ri=m+1,le=0;
    int mid;
    int i=0;
    while(le<=ri)
    {
        mid=(ri+le)/2;
        cout<<mid<<endl;
        cin>>t;
        if(!p[i%n])
            t=-t;
        if(t==0)
            return 0;
        else if(t==-1)//t<mid
            ri=mid;
        else le=mid;
        i++;
    }
    return 0;
}
/*  5 2 3
    1 0
*/