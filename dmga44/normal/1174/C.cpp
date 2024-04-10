#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 100005

int res[MAXN];

void criba()
{
    int cont=1;
    for(int i=2;i<MAXN;i++)
    {
        if(!res[i])
        {
            for(int j=i;j<MAXN;j+=i)
                if(!res[j])
                    res[j]=cont;
            cont++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();

    int n;
    cin >> n;
    for(int i=2;i<=n;i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}