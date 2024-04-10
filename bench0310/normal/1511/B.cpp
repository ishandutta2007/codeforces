#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto prime=[&](int a)->bool
    {
        if(a==1) return 0;
        for(int i=2;i*i<=a;i++) if((a%i)==0) return 0;
        return 1;
    };
    vector<array<int,2>> v(10,{0,0});
    vector<int> pw(10,1);
    for(int i=0;i<=9;i++)
    {
        if(i>0) pw[i]=(pw[i-1]*10);
        int j=0;
        for(int a=pw[i];j<2;a++) if(prime(a)) v[i][j++]=a;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        cout << pw[c-1]*v[a-c][0] << " " << pw[c-1]*v[b-c][1] << "\n";
    }
    return 0;
}