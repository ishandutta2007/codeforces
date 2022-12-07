#include <bits/stdc++.h>
using namespace std;
bool comp(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b)
{
    if(a.first.first==b.first.first) return a.first.second>b.first.second;
    else return a.first.first<b.first.first;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    pair <pair <int, int>, int> ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d%d", &ar[a].first.first, &ar[a].first.second);
        ar[a].second=a+1;
    }
    sort(ar, ar+n, comp);
    int an1=-1, an2=-1;
    for(int a=0; a+1<n; a++)
    {
        if(ar[a].first.second>=ar[a+1].first.second)
        {
            an1=ar[a+1].second, an2=ar[a].second;
        }
    }
    cout<<an1<<" "<<an2;
}