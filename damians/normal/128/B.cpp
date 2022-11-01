#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

#define MAX 1000002

char text[MAX]; long long key[MAX]; int N, sa[MAX], rank[MAX], *lcp=(int*)key;
struct Cmp { bool operator()(int i, int j) const { return key[i]<key[j]; } };
void build() {
for (int i = 0; i < N; i++) { sa[i] = i; key[i] = text[i]; }
sort(sa, sa+N, Cmp());
for (int K = 1; ; K *= 2) {
for (int i = 0; i < N; i++)
rank[sa[i]] = i>0 && key[sa[i-1]]==key[sa[i]] ? rank[sa[i-1]] : i;
if (K >= N) break;
for (int i = 0; i < N; i++)
key[i] = rank[i] * (N+1LL) + (i+K < N ? rank[i+K]+1 : 0);
sort(sa, sa+N, Cmp());
}
for (int i = 0, k = 0; i < N; i++) {
if (k > 0) k--;
if (rank[i] == N-1) { lcp[N-1] = -1; k = 0; continue; }
int j = sa[rank[i]+1];
while (text[i+k] == text[j+k]) k++;
lcp[rank[i]] = k;
}
}

int main()
{
    ios_base::sync_with_stdio(0);
    scanf("%s",text);
    int k;
    CZ(k);
    ll n=strlen(text);
    //DBG(n);
    //DBG(n*(n+1)/2);
    //DBG(k);
    if (k>(n*(n+1))/2)
    {
        puts("No such line.");
        return 0;
    }
    N=n;
    build();
    
    FOR(i,n)
    {
        REP(j,1,n-sa[i])
        {
            
            if (i && j<=lcp[i-1])
            {
                j=lcp[i-1];
                continue;
            }
            //DBG(mp(i,j));
            //DBG(k);
            int z=i+1;
            while(z<n && lcp[z-1]>=j) z++;
            int ile=z-i;
            if (k<=ile)
            {
                FOR(d,j) printf("%c",text[sa[i]+d]);
                return 0;
            }
            else k-=ile;
        }
    }
    
    

    return 0;
}