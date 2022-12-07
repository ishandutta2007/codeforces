#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    set <int> se;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        if(x!=0) se.insert(x);
    }
    cout<<se.size();
}