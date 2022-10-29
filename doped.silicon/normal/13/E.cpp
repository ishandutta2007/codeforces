#include <bits/stdc++.h>
 
using namespace std;
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)

/*Author Ritick Goenka || ritick(codechef) ||ritick(codeforces) */
/*IIT Roorkee = <3 */
#define ll int
#define ld double
#define ui unsigned int
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

 

 
inline int two(int n) {return 1 << n;}
inline int isOnBit(int n, int b) {return (n >> b) & 1;}
inline void onBit(int & n, int b) {n |= two(b);}
inline void offBit(int & n, int b) {n &= ~two(b);}
inline int lastBit(int n) {return n & (-n);}
inline int cntBit(int n) {int res = 0; while(n && ++res) n -= n &(-n); return res;}
 
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy8[] = {0, 1, 0, -1, -1, 1, -1, 1};
 
#define INP "test.inp"
#define OUT "test.out"
 

ll n,q;
int ar[100005];
ll k=400;
int nex[100005];
int last[100005];
int jump[100005];
int blk[100005];
int main () 
{
    ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        cin>>n>>q;
        
        rep(i,n)
        {
            cin>>ar[i+1];
            ar[i+1]=min(ar[i+1]+i+1,n+1);
        }
		for(ll i=1;i<=n+1;i++)
		{
			blk[i]=i/k+1;
		}
        for(ll i=n;i>=1;i--)
        {
            if(ar[i]>n||blk[i]!=blk[ar[i]])
            {
                nex[i]=ar[i];
                last[i]=i;
                jump[i]=1;
            }
            else
            {
                nex[i]=nex[ar[i]];
                last[i]=last[ar[i]];
                jump[i]=jump[ar[i]]+1;
            }
        }
        // debug(nex[0]);
        // debug(jump[0]);
        jump[n+1]=0;
        for(ll i=1;i<=q;i++)
        {
            ll x;
            cin>>x;
            // debug(x);
            if(x==0)
            {
                ll p,b;
                cin>>p>>b;
                ar[p]=b+p;
                ll bll=p/k+1;
                // debug(p);
                // debug(b);
                while(p<n&&bll==blk[p]&&p>0)
                {
                    if(ar[p]>n||blk[p]!=blk[ar[p]])
                    {
                        nex[p]=ar[p];
                        last[p]=p;
                        jump[p]=1;
                    }
                    else
                    {
                        nex[p]=nex[ar[p]];
                        last[p]=last[ar[p]];
                        jump[p]=jump[ar[p]]+1;
                    } 
                    p--;
                }
            }
            else
            {
                
                ll p;
                cin>>p;
                ll a=p,b=0;
                while(p<=n)
                {
                    a=last[p];
                    b+=jump[p];
                    p=nex[p];
                }
                // b+=jump[p];
                cout<<a<<" "<<b<<endl;
            }   
        }
        return 0;
}