#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 120

bool mk[MAXN],mk2[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    string s;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        for(int j=0;j<m;j++)
            if(s[j]=='B')
            {
                mk[i]=1;
                mk2[j]=1;
            }
    }

    int p1=0;
    while(!mk[p1])
        p1++;
    int p2=n-1;
    while(!mk[p2])
        p2--;

    int d1=0;
    while(!mk2[d1])
        d1++;
    int d2=m-1;
    while(!mk2[d2])
        d2--;

    cout << (p1+p2)/2+1 << ' ' << (d1+d2)/2+1 << '\n';


    return 0;
}