#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <ctime>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)REP(i,0,(int)(v)-1)
#define FORD(i,v)REPD(i,(int)(v)-1,0)
#define pb push_back
#define sz size
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define D(x)  ((x+8)%4)
#define INF 2000000000
using namespace std;
int c[4];
int d[4];
vector<char> op;
vector<int> nr;

int main()
{
    ios_base::sync_with_stdio(0);
    srand(time(0));
    FOR(i,4) cin>>d[i];
    int m,k;
    int w;
    int time=clock();
    FOR(zzz,1)
    {
        if (zzz%100==0 && (double((clock()-time))/CLOCKS_PER_SEC)>1.6) break;
        int prob=0;
        FOR(i,4) c[i]=d[i];
        op.clear();nr.clear();
        FOR(l,10)
        {
            int r=rand()%4;
            int s=rand()%2;
            if (s && c[D(r)]%2==0 && c[D(r+1)]%2==0)
            {
                c[D(r)]/=2;
                c[D(r+1)]/=2;
                op.pb('/');
                nr.pb(r);
            }
            else
            {
                c[D(r)]+=1;
                c[D(r+1)]+=1;
                op.pb('+');
                nr.pb(r);
            }
        }
    while (c[0]>1 || c[1]>1 || c[2]>1 || c[3]>1)
    {
        if (rand()%(12)==0)
        {
            int r=rand()%4;
            int s=rand()%2;
            if (s && c[D(r)]%2==0 && c[D(r+1)]%2==0)
            {
                c[D(r)]/=2;
                c[D(r+1)]/=2;
                op.pb('/');
                nr.pb(r);
            }
            else
            {
                c[D(r)]+=1;
                c[D(r+1)]+=1;
                op.pb('+');
                nr.pb(r);
            }
        }
        prob++;
        if (prob>400) break;
        w=0;
        FOR(i,4)
        {
            if (c[i]>w) {w=c[i];m=i;}
        }
        if (c[m]%2)
        {
            if (rand()%2) k=D(m-1); else k=D(m);
            op.pb('+');
            nr.pb(k);
            c[D(k)]++;
            c[D(k+1)]++;
            continue;
        }
        else
        {
            if (c[D(m-1)]>c[D(m+1)])
            {
                if (c[D(m-1)]%2==0)
                {
                    op.pb('/');
                    nr.pb(D(m-1));
                    c[D(m-1)]/=2;
                    c[m]/=2;
                    continue;
                }
                else
                {
                    op.pb('+');
                    nr.pb(D(m-2));
                    c[D(m-1)]++;
                    c[D(m-2)]++;
                    continue;
                }
            }
            else
            {
                if (c[D(m+1)]%2==0)
                {
                    op.pb('/');
                    nr.pb(D(m));
                    c[D(m+1)]/=2;
                    c[m]/=2;
                    continue;
                }
                else
                {
                    op.pb('+');
                    nr.pb(D(m+1));
                    c[D(m+1)]++;
                    c[D(m+2)]++;
                    continue;
                }
            }
        }
        
    }
    
    if (prob<=400)
    {
        
        FOR(i,op.sz())
        {
            cout<<op[i]<<nr[i]+1<<endl;
        }
        //DBG(op.sz());
        return 0;
    }
    }
    cout<<"-1"<<endl;
    
    return 0;
}