#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int N=5005;
int a[N],b[N],n,vala[N],valb[N];
void print(int i,int j)
{
    printf("? %d %d\n",i,j);
    fflush(stdout);
}
int ans[N];
void solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        print(0,i);
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        print(i,0);
        scanf("%d",&b[i]);
    }
    int sum=0;
    for(int now=0;now<n;now++)//a[0]=now
    {
        vala[0]=now;
        for(int j=0;j<n;j++) valb[j]=a[j]^now;
        for(int j=1;j<n;j++) vala[j]=b[j]^valb[0];
        int bl=1;
        for(int i=0;i<n;i++) if(vala[valb[i]]!=i) bl=0;
        if(bl)
        {
            sum++;
            if(sum==1) for(int i=0;i<n;i++) ans[i]=vala[i];
        }
    }
    puts("!");
    cout<<sum<<endl;
    for(int i=0;i<n;i++) printf("%d ",ans[i]);
}

int main()
{
    solve();
    return 0;
}