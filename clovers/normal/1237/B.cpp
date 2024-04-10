#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int N=500005;
const int inf=(int)1e9+1;
const ll INF=(ll)5e18;
int n,a[N],b[N],pos[N],bl[N];

void init()
{

}

void solve()
{
    scanf("%d",&n); int S=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]), pos[b[i]]=i;
    for(int i=1;i<=n;i++)
    {
        if(pos[a[i]]>S) bl[a[i]]=1;
        S=max(S,pos[a[i]]);
    }
    int sum=0;
    for(int i=1;i<=n;i++) sum+=bl[i]^1;
    cout<<sum<<endl;
}

int main()
{
    int TTT=1; //scanf("%d",&TTT);
    while(TTT--){init(); solve();}
    return 0;
}