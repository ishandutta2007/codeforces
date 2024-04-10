#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        int ar[n];
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        int l=-1, r=n;
        while(r-l>1)
        {
            int mid=(l+r)>>1, ok=1, cq=q;
            for(int a=mid; a<n; a++)
            {
                if(ar[a]>cq)
                {
                    if(cq) cq-=1;
                    else
                    {
                        ok=0;
                        break;
                    }
                }
            }
            if(ok) r=mid;
            else l=mid;
        }
        for(int a=0; a<r; a++) printf(ar[a]>q ? "0" : "1");
        for(int a=r; a<n; a++) printf("1");
        printf("\n");
    }
}