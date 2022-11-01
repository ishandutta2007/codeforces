#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x,y;
    cin >> n >> x >> y;
    if(x<y) swap(x,y);
    vector<int> c(x+y,0);
    for(int i=0;i<x+y;i++) c[i]=(n/(x+y)+(i<(n%(x+y))));
    vector<int> now((1<<x),0);
    int all=(1<<x)-1;
    auto mx=[](int &a,int b){a=max(a,b);};
    for(int i=0;i<x+y;i++)
    {
        vector<int> nxt((1<<x),0);
        for(int m=0;m<(1<<x);m++)
        {
            int nm=(m<<1)&all;
            mx(nxt[nm],now[m]);
            if(((m>>(x-1))&1)==0&&((m>>(y-1))&1)==0) mx(nxt[nm^1],now[m]+c[i]);
        }
        now=nxt;
    }
    int res=0;
    for(int i=0;i<(1<<x);i++) mx(res,now[i]);
    cout << res << "\n";
    return 0;
}