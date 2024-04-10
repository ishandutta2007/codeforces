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
#define N 200005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
vector<int> a, b, c;
char s[N];
int cnt[2];
int main()
{
    int T, n, A, B, C, D, i;
    cin >> T;
    while(T--)
    {
        cin >> A >> B >> C >> D;
        a.clear(), b.clear(), c.clear();
        scanf("%s", s+1);
        n = strlen(s+1);
        cnt[0] = cnt[1] = 0;
        for(i=1;i<=n;i++)
        {
            cnt[s[i]-'A'] ++;
        }
        if(cnt[0]!= A+C+D)
        {
            printf("NO\n");
            continue;
        }
        s[0] = s[1];
        s[n+1] = s[n];
        char st = s[0], ed;
        int last = 0;
        for(i=1;i<=n+1;i++)
        {
            if(s[i] == s[i-1])
            {
                ed = s[i-1];
                
                if(st == ed)
                {
                    if((i-1 - last) / 2 > 0)
                    {
                        c.push_back((i-1 - last) / 2);
                    }
                }
                else if(st == 'A')
                {
                    a.push_back((i-1 - last + 1) / 2); // one more AB
                }
                else
                    b.push_back((i-1 - last + 1) / 2);
                
                st = s[i];
                last = i;
            }
        }
        //debug(a.size());
        //debug(b.size());
        //debug(c.size());
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int len_a = a.size(), len_b = b.size(), len_c = c.size();
        int left = 0;
        for(i=0;i<len_a; i++)
        {
            if(C <= a[i])
            {
                left += max(0, a[i] - C - 1);
                C = 0;
                //break;
            }
            else
                C -= a[i];
        }
        
        for(i=0;i<len_c;i++)
        { 
            if(C <= c[i])
            {
                left += max(0, c[i] - C );
                C = 0;
            }
            else
                C -= c[i];
        }
        int last_i = len_b;
        if(C > 0)
        {
            for(i=len_b - 1; i>= 0; i--)
            {
                if(C <= b[i] - 1)
                {
                    left += max(0, b[i] - 1 - C );
                    C = 0;
                    last_i = i;
                    break;
                }
                else
                {
                    C -= b[i]-1;
                }
            }
            if(C > 0)
            {
                printf("NO\n");
                continue;
            }
        }
        for(i=last_i - 1; i>=0; i--)
        {
            left += b[i];
        }
        if(left >= D)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);