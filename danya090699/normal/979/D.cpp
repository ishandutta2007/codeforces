#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
set <int> se[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==1)
        {
            int x;
            scanf("%d", &x);
            for(int b=1; b*b<=x; b++)
            {
                if(x%b==0)
                {
                    se[b].insert(x), se[x/b].insert(x);
                }
            }
        }
        else
        {
            int x, k, s, cu=0;
            scanf("%d%d%d", &x, &k, &s);
            if(x%k==0)
            {
                auto l=se[k].begin(), r=se[k].upper_bound(s-x);
                if(l!=r)
                {
                    for(int b=16; b>=0; b--)
                    {
                        auto mid=se[k].lower_bound(cu+(1<<b));
                        if(cu+(1<<b)>s-x) mid=r;
                        if(x&(1<<b))
                        {
                            if(l!=mid) r=mid;
                            else
                            {
                                cu+=(1<<b), l=mid;
                            }
                        }
                        else
                        {
                            if(r!=mid)
                            {
                                l=mid, cu+=(1<<b);
                            }
                            else r=mid;
                        }
                    }
                    printf("%d\n", cu);
                }
                else printf("-1\n");
            }
            else printf("-1\n");
        }
    }
}