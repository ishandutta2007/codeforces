#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

int sqrtN;

struct Query{
    int s, e, n;
    Query() : Query(0, 0, -1) {}
    Query(int _s, int _e, int _n)
    {
        s = _s;
        e = _e;
        n = _n;
    }
    bool operator < (const Query &O) const{
        if(s/sqrtN != O.s/sqrtN) return s/sqrtN < O.s/sqrtN;
        return e < O.e;
    }
};

Query Q[200002];
int a[200002], ans[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    sqrtN = 400;
    string S; cin >> S;
    for(int i=1;i<=n;i++) a[i] = S[i-1] - '0';

    for(int i=1;i<=m;i++){
        int s, e; cin >> s >> e;
        Q[i] = Query(s, e, i);
    }
    sort(Q+1, Q+m+1);
    
    //for(int i=1;i<=m;i++) cout << Q[i].s << " " << Q[i].e << "\n";

    int s = Q[1].s, e = Q[1].e;
    int now = 1;
    int zo = 0;
    for(int i=s+1;i<=e;i++){
        if(a[i] != a[i-1]) continue;
        if(a[i] == 0)
        {
            if(zo <= 0) now++;
            zo--;
        }
        else
        {
            if(zo >= 0) now++;
            zo++;
        }
    }
    
    ans[Q[1].n] = now;
    

    for(int i=2;i<=m;i++)
    {
        while(Q[i].s < s){
            s--;
            if(a[s] != a[s+1]) continue;
            if(a[s] == 0)
            {
                if(zo <= 0) now++;
                zo--;
            }
            else
            {
                if(zo >= 0) now++;
                zo++;
            }
        }
        
        while(Q[i].e > e){
            e++;
            if(a[e] != a[e-1]) continue;
            if(a[e] == 0)
            {
                if(zo <= 0) now++;
                zo--;
            }
            else
            {
                if(zo >= 0) now++;
                zo++;
            }
        }
        
        while(Q[i].s > s){
            if(a[s] != a[s+1]) { s++; continue; }
            if(a[s] == 0)
            {
                zo++;
                if(zo <= 0) now--;
            }
            else
            {
                zo--;
                if(zo >= 0) now--;
            }
            s++;
        }

        while(Q[i].e < e){
            if(a[e] != a[e-1]) { e--; continue; }
            if(a[e] == 0)
            {
                zo++;
                if(zo <= 0) now--;
            }
            else
            {
                zo--;
                if(zo >= 0) now--;
            }
            e--;
        }

        ans[Q[i].n] = now;
    }

    for(int i=1;i<=m;i++) cout << ans[i] << "\n";
}