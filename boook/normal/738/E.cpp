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
#define RI(i) scanf("%d",&i)

/// ----------- default code ----------------
#define MAX 205000
#define INF 0x3f3f3f3f
int x[MAX] , n , m , use[MAX];
struct cmp
{
    bool operator()(int q,int w){
        return x[q] > x[w];
    }
};
struct FK
{
    bool operator()(int q,int w){
        return x[q] < x[w];
    }
};
int main()
{
    WHILENM(n,m){
        REP(i,n)RI(x[i]);
        priority_queue<int,vector<int>,cmp> pq;
        priority_queue<int,vector<int>,FK> fq;
        int mm = 0 , ans = 0;
        REP(i,n){
            if(i+1 == m){
                if(x[i] != 0)ans++;
            }
            else pq.push(i) , fq.push(i);
        }
        MEM(use,0) , use[m-1] = 1;
        int QQ = 0;
        while(pq.size())
        {
            int now = pq.top();
            if(use[now])pq.pop();
            else if(x[now] == 0) ans++ , QQ++ , pq.pop() , use[now] = 1;
            else if(x[now] <= mm)pq.pop() , use[now] = 1;
            else if(x[now] == mm+1)mm++ , use[now] = 1;
            else {
                if(QQ)QQ-- , mm++;
                else {
                    int u = fq.top();fq.pop();
                    while(fq.size() && use[u])u = fq.top() , fq.pop();
                    use[u] = 1;
                    mm++ , ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}