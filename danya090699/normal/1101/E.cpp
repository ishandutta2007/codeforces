#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, mama=0, mami=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        char s[3];
        scanf("%s", s);
        int x, y;
        scanf("%d%d", &x, &y);
        if(x<y) swap(x, y);
        if(s[0]=='+') mama=max(mama, x), mami=max(mami, y);
        else
        {
            if(x>=mama and y>=mami) printf("YES\n");
            else printf("NO\n");
        }
    }
}