#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll T = 1000000000000;
const int ST = 40;

int stt;
ll t,ans,n;
ll c[ST][ST];
ll sz[ST];

ll go(int block, ll ost, int stt)
{
    //cout << block << " " << ost << " " << stt << endl;
    if (ost == 0)return 0;
    if (block == 0)
    {
        if (stt==0 || ost==2 && stt==1)return 1;
        return 0;
    }
    if (2*ost<=sz[block])
        return go(block-1, ost, stt);
    else
    {
        ll res = c[block-1][stt];
        if (stt>0)res += go(block-1,ost-sz[block]/2, stt-1);
        return res;
    }
}

int main()
{
    cin >> n >> t;
    sz[0] = 2;
    c[0][0]=1;
    c[0][1]=1;
    for (int i=1; sz[i-1]*2<=T; i++)
    {
        sz[i] = sz[i-1]*2;
        for (int j=ST-1; j>0; j--)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        c[i][0]=c[i-1][0];
    }

    ans=0;
    stt=0;
    while (t%2==0){t/=2; stt++;}
    if (t!=1){cout << 0 << endl; return 0;}
    int i=0;
    while (n-sz[i]>=0)
    {
        n -= sz[i];
        ans += c[i][stt];
        i++;
    }
    ans += go(i,n,stt);
    cout << ans << endl;
    return 0;
}