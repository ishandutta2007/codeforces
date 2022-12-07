//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
int la[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    long long su=0, pr=0;
    for(int a=0; a<sz; a++) la[a]=-1;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        su+=pr+(a-la[x]);
        pr+=a-la[x], la[x]=a;
    }
    su=su*2-n;
    cout<<fixed<<setprecision(10)<<su/(1.0*n*n);
}