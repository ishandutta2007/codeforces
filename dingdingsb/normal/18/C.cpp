#include<cstdio>
using namespace std;
int a[(int)1e5+50];
int s[(int)1e5+50];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<n;i++)
        if(s[i]==s[n]-s[i])
            ans++;

    printf("%d",ans);
    return 0;
}