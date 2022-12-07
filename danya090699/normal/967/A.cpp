#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, s, fo=0;
    cin>>n>>s;
    int pr=-s;
    for(int a=0; a<n; a++)
    {
        int h, m;
        cin>>h>>m;
        m=h*60+m;
        if(m-pr>=2*s+1)
        {
            cout<<(pr+s)/60<<" "<<(pr+s)%60;
            fo=1;
            break;
        }
        pr=m+1;
    }
    if(fo==0) cout<<(pr+s)/60<<" "<<(pr+s)%60;
}