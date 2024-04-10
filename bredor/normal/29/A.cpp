//  228

#include <cstdio>
using namespace std;
int main()
{
    int n,a[101],b[101];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int d;
        scanf("%d",&a[i]);
        scanf("%d",&d);
        b[i]=a[i]+d;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j]&&a[j]==b[i])
            {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}