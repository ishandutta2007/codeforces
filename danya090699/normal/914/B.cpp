#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int ar[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        ar[x]++;
    }
    bool ok=0;
    for(int a=sz-1; a>=0; a--) if(ar[a]%2) ok=1;
    if(ok) cout<<"Conan";
    else cout<<"Agasa";
}