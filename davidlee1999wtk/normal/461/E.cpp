#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 100005
#define M 10
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int ch[N*5][5];
int tot = 1;
char s[N];
int min_l[5], tr[5][5], opt[5];
void Insert(char *s, int len)
{
    int x = 1, i;
    for(i=0;i<len;i++)
    {
        if(ch[x][s[i] - 'A'] == 0)
        {
            ch[x][s[i] - 'A'] = ++tot;
        }
        x = ch[x][s[i] - 'A'];
    }
}

void dfs(int x, int dep, int st)
{
    int i, v;
    for(i=0;i<4;i++)
    {
        v = ch[x][i];
        if(v == 0)
        {
            if(dep < min_l[st])
            {
                min_l[st] = dep;
                memset(tr[st], 0, sizeof(int) * 5);
                tr[st][i] = 1;
            }
            else if(dep == min_l[st])
                tr[st][i] = 1;
        }
        else
            dfs(v, dep+1, st);
    }
}

int main()
{
    LL n;
    int m;
    int i;
    cin >> n;
    scanf("%s", s+1);
    m = strlen(s+1);
    // add all length M substring to the Trie tree
    for(i=1;i<=m;i++)
        Insert(s+i, min(M, m-i+1));
    //debug(tot);
    for(i=0;i<4;i++)
    {
        min_l[i] = M+1;
        dfs(ch[1][i], 1, i);
        //debug(min_l[i]);
    }
    int min_a = M+1;
    for(i=0;i<4;i++)
    {
        min_a = min(min_a, min_l[i]);
        //debug(min_l[i]);
    }
    for(i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            //debug(i);
            //debug(j);
            //printf("%d %d %d\n", i, j, tr[i][j]);
            ;
        }
    for(i=0;i<4;i++)
    {
        if(min_a == min_l[i])
        {
            opt[i] = 1;
        }
    }
    // enumerate permutation, more specifically, a "rho" graph
    int j, k, per[5], tper[5];
    int best_v = INF;
    int b_ring[5], b_line[5], len_ring, len_line, c_ring;

    for(k=1;k<=4;k++)
    {
        for(i=0;i<4;i++)
            tper[i] = i+1;
        do
        {
            for(j=0;j<4;j++)
            {
                per[j] = tper[j] - 1;
                //printf("%d ", per[j]);
            }
            //cout<<endl;
            for(j=0;j<4;j++)
            {
                per[k] = j;
                // check validity
                int occur = -1;
                for(i=0;i<k;i++)
                {          
                    if(!tr[per[i]][per[i+1]])
                        break;
                    if(per[i] == per[k])
                        occur = i;
                }
                if(i!=k || occur == -1)
                    continue;
                
                //debug(occur);
                int now_v = 0, l = 0, now_lr = k - occur;
                for(i=0;i<occur;i++)
                {
                    now_v += (1-opt[per[i]]) << (10 - l);
                    l ++;
                }
                for(i = 0; l<11; l++)
                {
                    now_v += (1-opt[per[i + occur]]) << (10 - l);
                    i = (i + 1) % now_lr;
                }
                if(now_v < best_v)
                {
                    best_v = now_v;
                    len_line = occur;
                    len_ring = k - occur;
                    for(i=0;i<occur;i++)
                        b_line[i] = per[i];
                    c_ring = 0;
                    for(i=0;i<now_lr;i++)
                    {
                        c_ring += min_l[per[i + occur]];
                        b_ring[i] = per[i + occur];
                    }
                }
            }
        }while(next_permutation(tper, tper+4));
    }

    //printf("best_v = %x \n", best_v);
    //debug(c_ring);
    //debug(len_line);
    //debug(len_ring);

    LL ans = 0;
    for(i=0; i < len_line;i++)
    {
        n -= min_l[b_line[i]];
        ans ++;
        if(n <= 0)
            break;
    }
    ans += (n / c_ring) * len_ring;
    n %= c_ring;
    for(i=0; i < len_ring && n > 0;i++)
    {
        n -= min_l[b_ring[i]];
        ans ++;
        if(n <= 0)
            break;
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2022/
// srO myk Orz
//ios::sync_with_stdio(false);