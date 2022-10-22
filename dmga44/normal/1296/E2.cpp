#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 200005

bool ok[26][27];
int cc[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int v=s[i]-'a';
        bool mk[27];
        for(int j=0;j<27;j++)
            mk[j]=0;
        for(int j=v+1;j<26;j++)
            for(int k=1;k<=26;k++)
                if(ok[j][k])
                    mk[k]=1;
        int c=1;
        while(mk[c])
            c++;
        cc[i]=c;
        ok[v][c]=1;
        res=max(res,c);
    }

    db(res)
    for(int i=0;i<n;i++)
        cout << cc[i] << ' ';
    cout << '\n';

    return 0;
}