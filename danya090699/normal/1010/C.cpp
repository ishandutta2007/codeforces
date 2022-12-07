#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int x=k;
    for(int a=0; a<n; a++)
    {
        int va;
        scanf("%d", &va);
        x=__gcd(x, va%k);
    }
    cout<<k/x<<"\n";
    for(int a=0; a<k; a+=x) printf("%d ", a);
}