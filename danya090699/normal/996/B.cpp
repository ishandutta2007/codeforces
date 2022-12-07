#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, be=2e9, an;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int q;
        scanf("%d", &q);
        int x=de(max(q-a, 0), n);
        if(be>a+x*n)
        {
            be=a+x*n, an=a+1;
        }
    }
    cout<<an;
}