#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

const ll M1=1000000009,M2=1000000021;
Pll Atree[524288],Btree[524288];
ll p3[200005],p5[200005];
void upd(int node, int S, int E, int k, int dif)
{
    if (S == E)
    {
        if(dif&1)
        {
            Atree[node]=mp(2,2);
            Btree[node]=mp(1,1);
        }
        else
        {
            Atree[node]=mp(1,1);
            Btree[node]=mp(2,2);
        }
        return;
    }
    int M=S+E>>1;
    if (k <= M)upd(node * 2, S, M, k, dif);
    else upd(node * 2 + 1, M + 1, E, k, dif);
    Atree[node].X=(p3[E-M]*Atree[node<<1].X+Atree[node<<1|1].X)%M1,Atree[node].Y=(p5[E-M]*Atree[node<<1].Y+Atree[node<<1|1].Y)%M2;
    Btree[node].X=(p3[E-M]*Btree[node<<1].X+Btree[node<<1|1].X)%M1,Btree[node].Y=(p5[E-M]*Btree[node<<1].Y+Btree[node<<1|1].Y)%M2;
}
Pll find(int node, int S, int E, int i, int j,Pll tree[524288])
{
    if (i > E || j < S)return mp(-INF,-INF);
    if (i <= S && j >= E)return tree[node];
    int M=S+E>>1;
    Pll p1=find(node * 2, S, M, i, j,tree),p2=find(node * 2 + 1, M + 1, E, i, j,tree);
 
    if(p1.X==-INF)return p2;
    if(p2.X==-INF)return p1;
    Pll p;
    int tt=min(E,j)-M;
    p.X=(p3[tt]*p1.X+p2.X)%M1;
    p.Y=(p5[tt]*p1.Y+p2.Y)%M2;
    return p;
}
int cnt[200005];
char s[200005];
int main() {
    p3[0]=p5[0]=1;
    fup(i,1,200000,1)
    {
        p3[i]=(p3[i-1]*3)%M1;
        p5[i]=(p5[i-1]*5)%M2;
    }
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    fup(i,1,n,1)
    {
        cnt[i]=cnt[i-1];
        if(s[i]=='0')cnt[i]++;
    }
    int N=cnt[n],cc=0;
    fup(i,1,n,1)
    {
        if(s[i]=='0')
        {
            cc++;
            upd(1,1,N,cc,i);
        }
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x,y,len;
        scanf("%d%d%d",&x,&y,&len);
        if(cnt[y+len-1]-cnt[y-1]!=cnt[x+len-1]-cnt[x-1])
        {
            puts("No");
            continue;
        }
        if(cnt[y+len-1]-cnt[y-1]==0 && cnt[x+len-1]-cnt[x-1]==0)
        {
            puts("Yes");
            continue;
        }
        if(cnt[y+len-1]-cnt[y-1]==len && cnt[x+len-1]-cnt[x-1]==len)
        {
            puts("Yes");
            continue;
        }
        Pll p1=find(1,1,N,cnt[x-1]+1,cnt[x+len-1],x&1?Atree:Btree);
        Pll p2=find(1,1,N,cnt[y-1]+1,cnt[y+len-1],y&1?Atree:Btree);
        puts(p1==p2?"Yes":"No");
    }
}