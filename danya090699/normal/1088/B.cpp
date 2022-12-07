#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n], su=0, yk=0;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    sort(ar, ar+n);
    for(int a=0; a<k; a++)
    {
        int fo=0;
        while(yk<n)
        {
            if(ar[yk]>su)
            {
                ar[yk]-=su;
                printf("%d\n", ar[yk]);
                su+=ar[yk];
                fo=1, yk++;
                break;
            }
            else yk++;
        }
        if(fo==0) printf("0\n");
    }
}