#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
#define MAX 105
#define NIL
int gra[MAX][MAX];
typedef long long LL;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    while(cin >> n >> m) {
        for(int i = 1;i <= m;i++) for(int j = 1;j <= n;j++) scanf("%d",&gra[i][j]);
        int ans[MAX];
        memset(ans,0,sizeof ans);
        for(int i = 1;i <= m;i++) {
            int ma = gra[i][1];
            int now = 1;
            for(int j = 2;j <= n;j++) {
                if(gra[i][j] > ma) {
                    ma = gra[i][j];
                    now = j;
                }
            }
            ans[now]++;
        }
        int ma = ans[1];
        int now = 1;
        for(int i = 2;i <= n;i++) {
            if(ans[i] > ma) {
                now = i;
                ma= ans[i];
            }
        }
        printf("%d\n",now);
    }
    return 0;
}