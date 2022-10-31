#include <iostream>
#include <algorithm>
using namespace std;

struct box
{
    int n;
    int v;
};
int cmp(box a, box b)
{
    return a.v > b.v;
}

int main()
{
    int n,m,ans = 0;
    cin >> n >> m;
    box b[m];
    for(int k =0 ; k < m ; k++)
        cin >> b[k].n >> b[k].v;
    sort(b,b+m,cmp);
    for(int k = 0; k < m && n >0 ; k++)
    {
        ans += min(b[k].n, n) * b[k].v;
        n -= b[k].n;
    }
    cout << ans << endl;
    return 0;
}