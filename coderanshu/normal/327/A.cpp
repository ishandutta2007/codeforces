#include<iostream>


int a[100];

int main()
{
    int n;
    scanf("%d",&n);
    int ans = 0;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
        ans += a[i];
    }
    int u = ans;
    ans = 0;
    for(int i=0;i<n;++i)
    {
        int sum = 0;
        for(int j=i;j<n;++j)
        {
            sum += a[j] == 1 ? -1 : 1;
            if(u + sum > ans)
                ans = u + sum;
        }
    }
    printf("%d\n",ans);
}