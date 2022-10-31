#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k,s;
    cin>>n>>k>>s;
    int first=1;
    if(k*(n-1)<s||k>s)
    {
        puts("NO");
        return 0;
    }
    else puts("YES");
    int flag=1;
    while(s-k>=n-1)
    {
        s-=n-1;
        if(flag)
        {
            if(first)
            {
                printf("%d",n);
                first=0;
            }
            else printf(" %d",n);
            flag=0;
            k--;
        }    
        else{
            printf(" 1");
            flag=1;
            k--;
        }
    }
    
    if(flag==1)
    {
        if(first) {printf("%d",s-k+2); first=0;}
        else printf(" %d",s-k+2);
        int now=s-k+2;
        s-=s-k-1;
        k--;
        while(k--)
        {
            if(now<n)
                printf(" %d",++now);
            else printf(" %d",--now);
        }
    }
    else {
        printf(" %d",n-s+k-1);
        int now=n-s+k-1;
        s-=s-k-1;
        k--;
        while(k--)
        {
            if(now>1)
                printf(" %d",--now);
            else printf(" %d",++now);
        }
    }
    cout<<endl;
    return 0;
}