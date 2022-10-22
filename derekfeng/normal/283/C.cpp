#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bitset>
using namespace std;
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
const long long mod = 1000000007;
#define all(c) (c).begin(),(c).end()
#define forn(i,a,b) for(int i=a;i<b;i++)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])
#define pb push_back
int main(){
    int n,q,tn;
    scanf("%d%d%d",&n,&q,&tn);
    ll t = tn;
    readv(a,n);
    vi m(n,-1),l(n,-1);
    forn(i,0,q){
        int b,c;
        scanf("%d %d", &b, &c);
        b--;c--;
        m[b]=c;
        l[c]=b;
    }
    vi vis(n,0);
    vll can;
    forn(i,0,n){
        if(!vis[i]){
            deque<int> p;
            p.pb(i);
            while(m[p.front()]!=-1){
                p.push_front(m[p.front()]);
                if(vis[p.front()]){
                    cout<<0;
                    return 0;
                }
                vis[p.front()]=1;
            }
            while(l[p.back()]!=-1){
                p.push_back(l[p.back()]);
                if(vis[p.back()]){
                    cout<<0;
                    return 0;
                }
                vis[p.back()] = 1;
            }
            reverse(all(p));
            int k=p.size();
            if(k==1) can.pb(a[p[0]]);
            else{
                ll sum=0;
                forn(j,0,k){
                    sum+=a[p[j]];
                    if(j<k-1) t-=sum;
                    can.pb(sum);
                }
            }
        }
    }
    if(t<0) cout<<0;
    else if(t==0) cout<<1;
    else {
        vll d(t+1,0);
        d[0]=1;
        for(auto x:can) {
            for(int i=0;i<=t-x;i++) d[i+x]=(d[i+x]+d[i])%mod;
        }
        cout<<d[t];
    }
}