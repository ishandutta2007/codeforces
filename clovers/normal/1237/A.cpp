#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int N=500005;
const int inf=(int)1e9+1;
const ll INF=(ll)5e18;
int n,a[N];

void init()
{

}

int bl=0;
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]%2==0) a[i]/=2;
        else 
        {
            if(bl==0) bl+=(a[i]/2)*2-a[i],a[i]=a[i]/2;
            else if(bl==1) 
            {
                if(a[i]<0) a[i]=a[i]/2-1;
                else a[i]/=2;
                bl=0;
            }
            else
            {
                if(a[i]<0) a[i]=a[i]/2;
                else a[i]=a[i]/2+1;
                bl=0;
            }
        }
    }
    for(int i=1;i<=n;i++) printf("%d\n",a[i]);
}

int main()
{
    int TTT=1; //scanf("%d",&TTT);
    while(TTT--){init(); solve();}
    return 0;
}