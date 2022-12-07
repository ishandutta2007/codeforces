#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, pr, an=0;
    cin>>n>>k>>pr;
    vector <int> sp;
    for(int a=1; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        sp.push_back(x-pr), an+=x-pr, pr=x;
    }
    sort(sp.begin(), sp.end(), greater <int>());
    for(int a=0; a<k-1; a++) an-=sp[a];
    cout<<an;
}