//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int ar[sz];
bool comp(int a, int b){return ar[a]>ar[b];}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar2[n];
    for(int a=0; a<n; a++)
    {
        ar2[a]=a;
        scanf("%d", &ar[a]);
    }
    sort(ar2, ar2+n, comp);
    int ar3[n+2], yk=0, ma=0;
    for(int a=0; a<n+2; a++) ar3[a]=0;
    for(int a=1; a<=n; a++)
    {
        while(ma<a)
        {
            int pos=ar2[yk]+1;
            int l=ar3[pos-1], r=ar3[pos+1];
            ma=max(ma, l+1+r);
            ar3[pos-l]=l+1+r, ar3[pos+r]=l+1+r;
            yk++;
        }
        printf("%d ", ar[ar2[yk-1]]);
    }
}