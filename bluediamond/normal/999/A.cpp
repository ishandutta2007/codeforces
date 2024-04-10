#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,k,v[105];
int st,dr;

bool e=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        if(v[i]>k)
            e=1;
    }
    st=1;
    dr=n;
    if(e==0)
    {
        cout<<n<<"\n";
        return 0;
    }
    while(v[st]<=k)
        st++;
    while(v[dr]<=k)
        dr--;
    cout<<st+n-dr-1<<"\n";
    return 0;
}
/**

**/