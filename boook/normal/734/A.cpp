#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int , int> PII;
#define REP(i,j) for(int i=0;i<j;i++)
#define REPNM(i,j,k) for(int i=j;i<k;i++)
#define RREP(i,j,k) for(int i=j;i>=k;i--)
#define MEM(i,j) memset(i,j,sizeof i)
#define WHILE(n) while(~scanf("%d",&n))
#define WHILE_(n) while(~scanf("%d",&n) && n)
#define WHILENM(n,m) while(~scanf("%d%d",&n,&m))
#define WHILENM_(n,m) while(~scanf("%d%d",&n,&m) && (n || m) )
#define pb push_back
#define mp make_pair
#define A first
#define B second
#define AC 53LL
#define AMOD 1000000079LL
#define debug 0
#define DB() if(debug)

/// ----------- default code ----------------
#define MAX 10
#define INF 0x3f3f3f3f

int x[MAX];
int t , n;

int main()
{
    WHILE(t){
        string s;
        cin>>s;
        int q = 0 , w = 0;
        REP(i,s.size()){
            if(s[i] == 'A')q++;
            else w++;
        }
        if(q == w)puts("Friendship");
        else if(q > w)puts("Anton");
        else puts("Danik");
    }
    return 0;
}