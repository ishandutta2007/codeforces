#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
typedef pair<int,int> pii;
#define mk make_pair
const int N=50005;
const int inf=(int)1e9+1;
const ll INF=(ll)5e18;

int n;
struct node{
    int x,y,z,id;
    bool operator < (const node &rhs) const{
        if(x==rhs.x) 
        {
            if(y==rhs.y) return z<rhs.z;
            return y<rhs.y;
        }
        return x<rhs.x;
    }
}a[N];

void init()
{

}

int dist(node A,node B)
{
    return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) +(A.z-B.z)*(A.z-B.z) ;
}

set<node> st;
vector<pii> ans;
int bl[N];
void solve()
{
    scanf("%lld",&n); ans.clear();
    for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z), a[i].id=i;
    for(int i=1;i<=n;i++)
    {
        if(bl[i]) continue;
        int dis=INF,id;
        for(int j=i+1;j<=n;j++) if(!bl[j]&&dis>dist(a[i],a[j])) id=j,dis=dist(a[i],a[j]);
        printf("%lld %lld\n",i,id);
        bl[id]=1;
    }
}

signed main()
{
    int TTT=1; //scanf("%d",&TTT);
    while(TTT--){init(); solve();}
    return 0;
}