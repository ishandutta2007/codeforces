#include <bits/stdc++.h>
using namespace std;
const int inf=2e5;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    cout<<n+1<<"\n";
    cout<<1<<" "<<n<<" "<<inf<<"\n";
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        x+=inf;
        cout<<2<<" "<<a+1<<" "<<x-a<<"\n";
    }
}