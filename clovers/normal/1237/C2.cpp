//think:1D->2D->3D
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int N=50005;
const int inf=(int)1e9+1;
const ll INF=(ll)5e18;

int n;
struct node{
    int x,y,z,id;
}a[N];
bool cmp1(node A,node B){return A.x<B.x;}
bool cmp2(node A,node B){return A.y<B.y;}
bool cmp3(node A,node B){return A.z<B.z;}

void init()
{

}

int dist(node A,node B)
{
    return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) + (A.z-B.z)*(A.z-B.z) ;
}

set<node> st;
vector<pii> ans;
int bl[N];
vector<int> tmp;

void solve1(int L,int R)
{
    sort(a+L,a+R+1,cmp3);
    for(int i=L;i<R;i+=2)
    {
        printf("%d %d\n",a[i].id,a[i+1].id);
        bl[a[i].id]=1; bl[a[i+1].id]=1;
    }
}

void solve2(int L,int R)
{
    sort(a+L,a+R+1,cmp2);
    for(int i=L,l,r;i<=R;i=r+1)
    {
        l=i; r=i; while(a[r+1].y==a[l].y&&r<R) r++;
        solve1(l,r);
    }
    int tmp=0;
    for(int i=L;i<=R;i++) if(!bl[a[i].id])
    {
        if(!tmp) tmp=a[i].id;
        else 
        {
            printf("%d %d\n",tmp,a[i].id);
            bl[a[i].id]=1; bl[tmp]=1; tmp=0;
        }
    }
}

void solve()
{
    scanf("%d",&n); ans.clear();
    for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z), a[i].id=i;
    sort(a+1,a+n+1,cmp1);
    for(int i=1,l,r;i<=n;i=r+1)
    {
        l=i; r=i; while(a[r+1].x==a[l].x&&r<n) r++;
        solve2(l,r);
    }
    int tmp=0;
    for(int i=1;i<=n;i++) if(!bl[a[i].id])
    {
        if(!tmp) tmp=a[i].id;
        else printf("%d %d\n",tmp,a[i].id), tmp=0;
        bl[a[i].id]=1;
    }
}

signed main()
{
    int TTT=1; //scanf("%d",&TTT);
    while(TTT--){init(); solve();}
    return 0;
}