#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int w, l, an=2e9;
    cin>>w>>l;
    int ar[w-1];
    for(int a=0; a<w-1; a++) scanf("%d", &ar[a]);
    int yk=0, cu=0;
    for(int a=0; a+l<=w-1; a++)
    {
        while(yk<a+l)
        {
            cu+=ar[yk], yk++;
        }
        an=min(an, cu);
        cu-=ar[a];
    }
    cout<<an;
}