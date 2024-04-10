#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int q;
    cin>>q;
    while (q--)
    {
        string s;
        cin>>s;
        int lcnt = 0, rcnt = 0, ucnt = 0, dcnt = 0;
        for (auto &x : s)
        {
            if (x == 'L') lcnt++;
            if (x == 'R') rcnt++;
            if (x == 'U') ucnt++;
            if (x == 'D') dcnt++;
        }
        int lr = min(lcnt, rcnt);
        int ud = min(ucnt, dcnt);
        if (!ud)
            lr = min(lr, 1);
        if (!lr)
            ud = min(ud, 1);
        printf("%i\n", lr * 2 + ud * 2);
        for (int x = 0; x < lr; x++)
            printf("L");
        for (int x = 0; x < ud; x++)
            printf("U");
        for (int x = 0; x < lr; x++)
            printf("R");
        for (int x = 0; x < ud; x++)
            printf("D");
        printf("\n");
    }
}