#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, pr=0, an=0;
    cin>>n;
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        ma[x]++;
    }
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        int q=(*it).second;
        int q2=min(pr, q);
        an+=q2, pr-=q2;
        pr+=q;
    }
    cout<<an;
}