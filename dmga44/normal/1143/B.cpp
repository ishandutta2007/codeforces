#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int po[12];

vector<int> digits(int x)
{
    vector<int> res;
    while(x)
    {
        res.push_back(x%10);
        x/=10;
    }

    reverse(res.begin(),res.end());

    return res;
}

int hel(int x)
{
    int res=1;
    while(x>=10)
    {
        res*=9;
        x/=10;
    }
    return res;
}

int marcelo(int n)
{
    if(n<10)
        return n;
    vector<int> d=digits(n);
    if(d[0]==1)
        return hel(n);
    return max((d[0]-1)*hel(n),d[0]*marcelo(n-(d[0]*po[d.size()-1])));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    po[0]=1;
    for(int i=1;i<11;i++)
        po[i]=po[i-1]*10;

    int n;
    cin >> n;
    db(marcelo(n))

    return 0;
}