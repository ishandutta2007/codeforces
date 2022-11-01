#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

int n,m,k;

int main()
{
        scanf("%d%d%d",&n,&m,&k);
        VI nim;
        bool cool1 = false;
        bool cool2 = false;
        REP(i,n)
        {
                int j1 = -1, j2 = -1;
                char c1,c2;
                REP(j,m)
                {
                        char c;
                        do c = getc(stdin);
                        while (c!='G'&&c!='R'&&c!='-');
                        if (c!='-')
                                if (j1==-1)
                                        j1=j,c1=c;
                                else
                                        j2=j,c2=c;
                }
                if (j1==-1&&j2==-1) continue;
                if (j1!=-1 && m==1 || j1!=-1 && j2!=-1 && m==2) continue; //locked
                if (j1!=-1&&j2!=-1 && c1!=c2) // interesting
                {
                        nim.pb(abs(j1-j2)-1);
                        continue;
                }
                // only one type, moves freely
                if (c1=='G')
                        cool1=true;
                else
                        cool2=true;
        }
        string res;
        if (cool1&&cool2)
                res = "Draw";
        else if (cool1)
                res = "First";
        else if (cool2)
                res = "Second";
        else
        {
                int d[32];
                CLEAR(d);
                REP(i,SZ(nim))
                {
                        for (int x = nim[i], j=0; x; x/=2,j++)
                                d[j] = (d[j]+x%2)%(k+1);
                }
                int s = 0;
                REP(i,32)
                        s+=d[i];
                if (s)
                        res = "First";
                else
                        res = "Second";
        }
        printf("%s\n",res.c_str());
        return 0;
}