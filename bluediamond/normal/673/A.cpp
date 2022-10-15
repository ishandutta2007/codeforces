#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,lst=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(a-lst>15)
        {
            cout<<lst+15<<"\n";
            return 0;
        }
        lst=a;
    }
    cout<<min(90,lst+15)<<"\n";
    return 0;
}