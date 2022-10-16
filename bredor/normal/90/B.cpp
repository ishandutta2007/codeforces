//  228

#include<iostream>
#include<iomanip>
#include<vector>
#include<math.h>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cstdlib>
#include<climits>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>

#define     fi(x,y) for(ll i(x); i<y; i++)      //fl(0,n)
#define     fj(x,y) for(ll j(x); j<y; j++)
#define     fk(x,y) for(ll k(x); k<y; k++)
#define     fa(x) for(auto i:x)                     //range based
#define     fri(x,y) for(ll i(x); i>=y; i--)    //reverse for loop
#define     frj(x,y) for(ll j(x); j>=y; j--)
#define     frk(x,y) for(ll k(x); k>=y; k--)

#define     ll              long long
#define     ld              long double
#define     ull             unsigned long long
#define     pq              priority_queue
#define     pb              push_back
#define     umap            unordered_map
#define     uset            unordered_set
#define     mod             ((ull)pow(10,9)+7)
#define     pll             pair<ll,ll>
#define     pii             pair<int,int>
using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);
 
        return h1 ^ h2;
    }
};

ull max(ull a[], ull b[]){
    ull r(*a);
    ull *k=a;
    while(k!=b){
        r = (r>(*k))?r:(*k);
        k++;
    }
    return r;
}

ull min(ull a[], ull b[]){
    ull r(*a);
    ull *k=a;
    while(k!=b){
        r = (r<(*k))?r:(*k);
        k++;
    }
    return r;
}

void sieve(bool prime[], int n)
{
    memset(prime, true, sizeof(bool)*n);
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

template<typename T>
bool compair(pair<T,T> a, pair<T,T> b){
    // return a.second>b.second;   //desc
    return a.second<b.second;   //asc
}

void solve(){
    
    int n,m;
    cin>>n>>m;

    char inp[n][m];
    bool tri[n][m];
    fi(0,n)fj(0,m)cin>>inp[i][j];
    memset(tri,true,sizeof(tri));

    fi(0,n){
        fj(0,m){

            // Col:
            fk(j+1,m){
                if(inp[i][j] == inp[i][k]){
                    tri[i][j] = tri[i][k] = false;
                }
            }

            // Row:
            fk(i+1,n){
                if(inp[i][j] == inp[k][j]){
                    tri[i][j] = tri[k][j] = false;
                }
            }
        
        }
    }
    fi(0,n)fj(0,m)if(tri[i][j])cout<<inp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // bool s[1000001];
    // sieve(s, 1000000);
    // ull t;
    // cin>>t;
    // while(t--)
    {solve();}
    return 0;
}