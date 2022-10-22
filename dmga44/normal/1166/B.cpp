#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;
    pii x=pii(-1,-1);
    for(int i=5;i<=k;i++)
        if(k%i==0 && min(i,k/i)>=5)
            x=pii(i,k/i);
    if(x==pii(-1,-1))
    {
        db(-1)
        return 0;
    }

    char c[5];
    c[0]='a';
    c[1]='e';
    c[2]='i';
    c[3]='o';
    c[4]='u';
    for(int i=0;i<x.first;i++)
        for(int j=0;j<x.second;j++)
            cout << c[(i+j)%5];

    return 0;
}