#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
typedef pair<int,int> pii;
#define mk make_pair
const int N=500005;
const int inf=(int)1e9+1;
const ll INF=(ll)5e18;

void init()
{

}

ll gcd(ll x,ll y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}

int n,a[N],k;
pii A[6];

bool check(int mid)
{
    ll ret=0;
    int tmp3=mid/A[3].second;
    int tmp1=mid/A[1].second-tmp3;
    int tmp2=mid/A[2].second-tmp3;
    //cout<<mid<<" "<<tmp1<<" "<<tmp2<<" "<<tmp3<<endl;
    for(int i=n;i>=1;i--)
    {
        if(tmp3) tmp3--,ret+=a[i]*A[3].first;
        else if(tmp2) tmp2--,ret+=a[i]*A[2].first;
        else if(tmp1) tmp1--,ret+=a[i]*A[1].first;
        else break;
        //if(mid==6) cout<<a[i]<<" "<<ret<<endl;
    }
    return ret>=k;
}

void solve()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]), a[i]/=100;
    sort(a+1,a+n+1);
    scanf("%lld%lld",&A[1].first,&A[1].second);
    scanf("%lld%lld",&A[2].first,&A[2].second);
    scanf("%lld",&k);
    A[3].first=A[1].first+A[2].first;
    A[3].second=A[1].second*A[2].second/gcd(A[1].second,A[2].second);
    int l=1,r=n,mid,best=-1;
    sort(A+1,A+4);
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid)) r=mid-1,best=mid;
        else l=mid+1;
    }
    printf("%lld\n",best);
}

signed main()
{
    int TTT=1; scanf("%lld",&TTT);
    while(TTT--){init(); solve();}
    return 0;
}