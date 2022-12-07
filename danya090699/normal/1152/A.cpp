#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int qq[2], q[2][2]={{0, 0}, {0, 0}};
    cin>>qq[0]>>qq[1];
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<qq[i]; a++)
        {
            int x;
            scanf("%d", &x);
            q[i][x&1]++;
        }
    }
    cout<<min(q[0][0], q[1][1])+min(q[1][0], q[0][1]);
}