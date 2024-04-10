#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int N=500005;

void init()
{

}

int n,t[N],num[N],a[N],now[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),t[n-a[i]]++;
    for(int i=1;i<=n;i++) a[i]=n-a[i];
    for(int i=1;i<=n;i++)
    {
        if(t[a[i]]%a[i])
        {
            puts("Impossible");
            return;
        }
    }
    puts("Possible");
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<" "<<cnt<<endl;
        if(!num[a[i]]&&!now[a[i]])
        {
            num[a[i]]=++cnt; 
            now[a[i]]=1;
            int tmp=a[i]; a[i]=num[a[i]]; 
            if(now[tmp]%tmp==0) now[tmp]=0,num[tmp]=++cnt;
            continue;
        }
        else now[a[i]]++;
        //cout<<i<<" "<<now[a[i]]<<" "<<cnt<<endl;
        int tmp=a[i]; 
        if(now[tmp]>tmp) now[tmp]=1,num[tmp]=++cnt;
        a[i]=num[a[i]];
    }
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    cout<<endl;
}

int main()
{
    int TTT=1; //scanf("%d",&TTT);
    while(TTT--){init(); solve();}
    return 0;
}