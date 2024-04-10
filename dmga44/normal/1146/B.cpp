#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 100005

char arr[MAXN];
int p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string t;
    cin >> t;
    int n=t.size();
    int d=0;
    for(int i=0;i<n;i++)
        if(t[i]!='a')
        {
            p[d]=i;
            arr[d]=t[i];
            d++;
        }

    if(d&1)
    {
        db(":(")
        return 0;
    }
    else if(!d)
    {
        db(t)
        return 0;
    }

    bool ok=1;
    for(int i=0;i<d/2;i++)
        ok&=(arr[i]==arr[i+d/2]);
    for(int i=p[d/2];i<n;i++)
        ok&=(t[i]!='a');
    if(ok)
        for(int i=0;i<p[d/2];i++)
            cout << t[i];
    else
        db(":(")

    return 0;
}