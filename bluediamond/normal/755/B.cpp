#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int n,m;

int x[3];

map<string,int>ap;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        ap[s]++;
    }
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        ap[s]++;
    }
    for(auto &it:ap)
        x[it.second]++;

    int com=x[2];
    int onlyA=n-com;
    int onlyB=m-com;

    int turn=2;

    while(1)
    {
        turn=3-turn;
        if(com==0)
        {
            if(turn==1 && onlyA==0) break;
            if(turn==2 && onlyB==0) break;
        }
        if(com)
        {
            com--;
            continue;
        }
        if(turn==1) onlyA--;
        else onlyB--;
    }

    if(turn==1) cout<<"NO\n";
    else cout<<"YES\n";

    return 0;
}
/**



**/