#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
#define psi pair<string,int>
#define pis pair<int,string>
#define piii pair<int,pii>


int power(int x, int y, int p)
{
    int res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
int modInverse(int n, int p)
{
    return power(n, p-2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
int nCr(int n, int r, int p)
{
   // Base case
   if (r==0)
      return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    int fac[n+1];
    fac[0] = 1;
    for (int i=1 ; i<=n; i++)
        fac[i] = fac[i-1]*i%p;

    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}


int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin>>n;
    char c[n+10];
    cin>>c;ll j=0,k=0;
    for(ll i=1;i<n;i++){
        if(c[i]!=c[i-1]){k=i;if(j==0)j=i;}
    }
    ll ans=0;
    if(c[0]==c[k]){
        ans+=(j+1)*(n-k+1);
        ans%=MM;
        cout<<ans;return 0;
    }
    if(j==k){
        ans+=n-k+1;
        ans+=j;
        ans%=MM;
        cout<<ans;return 0;
    }
    ans+=n-k;
    ans+=j+1;
    ans%=MM;
    cout<<ans;
}