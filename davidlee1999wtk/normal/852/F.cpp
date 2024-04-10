// F.cpp : 
//

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
#define debug(x) cerr<<#x<<"="<<x<<endl
int P;
int ksm(int a, int b, int P)
{
    int c = 1, d = a;
    while (b)
    {
        if (b & 1)
            c = (LL)c*d%P;
        d = (LL)d*d%P;
        b >>= 1;
    }

    ///debug(c);
    return c;
}
vector<int> ans;
int main()
{
    int n, m, a, q, now, i, C;
    cin >> n >> m >> a >> q;
    now = a%q;
    for (i = 1; ; i++)
    {
        if (now == 1)
            break;
        now = (LL)now * a%q;
    }
    P = i;
    now = 1;
    C = 1;
    //debug(P);
    //P = 31;
    for (i = 1; i <= n; i++)
    {
        //debug(now);
        //printf("%d ", ksm(a,now, q));
        ans.push_back(ksm(a, now, q));
        if (i <= m)
            C = (LL)C * (m - i + 1) % P*ksm(i, P - 2, P)%P;
        else C = 0;
        //debug(C);
        //debug(P);
        now = (now + C) % P;
    }
    reverse(ans.begin(), ans.end());
    for (auto it : ans)
        printf("%d ", it);
    cout << endl;
    
    return 0;
}