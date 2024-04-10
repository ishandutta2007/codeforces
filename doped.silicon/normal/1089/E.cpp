#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define debug(x) cout<<#x<<": "<<x<<endl

#define ld double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000000000000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cout<<"a1 ";
    ll n;
    cin>>n;
    ll x=0,num=2;char c='a',last=1;
    ll ar[10];
    		rep(i,10)
    		{
    			ar[i]=0;
    		}
    while(n--)
    {
    	if(n<=7&&num!=8)
    	{
    		num=last;
    		c='h';
    		n++;
    		
    		while(n--)
    		{
    			if(n==0)
    			{
    				cout<<c<<"8 ";
    			}
    			else
    			{
    				while(ar[num]!=0)
    				{
    					num=(num)%7+1;
    				}
    				cout<<c<<num<<" ";
    				ar[num]=1;
    			}
    		}
    		break;
    	}
    	else
    	{
    		if(x==1)
    		{
    			cout<<c<<num<<" ";
    			last=num;
    			if(c=='h')
    			{
    				ar[num]=1;
    			}
    			num--;
    			if(num==0)
    			{
    				num=1;
    				x=0;
    				c=(char)c+1;
    			}
    			if(num==5&&n>9)
    			{
    				n--;
    				cout<<c<<"8 ";
    			}

    		}
    		else
    		{
    			cout<<c<<num<<" ";
    			last=num;
    			if(c=='h')
    			{
    				ar[num]=1;
    			}
    			num++;
    			if(num==8)
    			{
    				num=7;
    				x=1;
    				c=(char)c+1;
    			}
    			if(num==6&&n>9)
    			{
    				//debug(n);
    				n--;
    				cout<<c<<"8 ";
    			}
    		}
    	}

    }
}