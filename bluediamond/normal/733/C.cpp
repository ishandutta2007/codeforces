#include <iostream>

using namespace std;

typedef long long ll;
typedef long double ld;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N=500+5;
int n,a[N];
int m,b[N];
int st[N],dr[N];
int ma[N],pp[N];
string f[N];

bool ok()
{
    int p=1;
    int s=0;
    st[1]=1;
    for(int i=1;i<=n;i++)
    {
        dr[p]=i;
        s+=a[i];
        if(s>b[p]) return 0;
        if(s==b[p])
        {
            s=0;
            p++;
            st[p]=i+1;
            if(p>m && i<n) return 0;
        }
    }
    if(p!=m+1) return 0;
    for(int i=1;i<=m;i++)
    {
        if(st[i]==dr[i]) continue;
        bool ok=0;
        for(int j=st[i];j<=dr[i];j++)
        {
            if(a[j]!=a[st[i]]) ok=1;
            ma[i]=max(ma[i],a[j]);
        }
        if(ok==0) return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n; for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m; for(int i=1;i<=m;i++) cin>>b[i];
    if(ok()==0)
    {
        cout<<"NO\n"; return 0;
    }
    cout<<"YES\n";
    for(int i=1;i<=m;i++)
    {
        if(st[i]==dr[i]) continue;
        for(int j=st[i];j<=dr[i];j++)
        {
            if(a[j]!=ma[i]) continue;
            if(j==st[i])
            {
                if(a[j+1]!=a[j])
                {
                    pp[i]=j; f[i]="R"; break;
                }
                continue;
            }
            if(j==dr[i])
            {
                if(a[j-1]!=a[j])
                {
                    pp[i]=j; f[i]="L"; break;
                }
                continue;
            }
            if(a[j-1]!=a[j])
            {
                pp[i]=j; f[i]="L"; break;
            }
            if(a[j+1]!=a[j])
            {
                pp[i]=j; f[i]="R"; break;
            }
        }
        int bv=i-1;
        cout<<bv+(pp[i]-st[i]+1)<<" "<<f[i]<<"\n";
        int poz=bv+(pp[i]-st[i]+1);
        int r=-1;
        if(f[i]=="L")
        {
            r=dr[i]-pp[i];
            poz--;
        }
        else
        {
            r=dr[i]-pp[i]-1;
        }
        int l=dr[i]-st[i]-1-r;

        for(int i=1;i<=r;i++) cout<<poz<<" R\n";
        for(int i=1;i<=l;i++) cout<<poz--<<" L\n";
    }
}