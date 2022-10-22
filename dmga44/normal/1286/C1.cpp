#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 105

int sum[MAXN][26],pos[MAXN][2],pos2[MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cout << "? 1 " << n << '\n';
    cout.flush();
    vector<string> ss[n+1];
    for(int i=0;i<(n*(n+1))/2;i++)
    {
        string s;
        cin >> s;
        ss[s.size()].push_back(s);
    }

    for(auto y : ss[n][0])
        sum[n][y-'a']++;
    string base=ss[n][0];
    for(int i=n-1;i>=(n+1)/2;i--)
    {
        for(auto s : ss[i])
            for(auto c : s)
                sum[i][c-'a']++;
        for(int j=n-1;j>i;j--)
        {
            sum[i][pos[j][0]]+=(j-i+1);
            sum[i][pos[j][1]]+=(j-i+1);
        }
        for(int j=0;j<26;j++)
        {
            sum[i][j]-=sum[n][j]*(n-i+1);
            sum[i][j]*=-1;
        }
        vector<int> ok;
        for(int j=0;j<26;j++)
            for(int jj=0;jj<sum[i][j];jj++)
                ok.push_back(j);
        pos[i][0]=ok[0];
        pos[i][1]=ok[1];
    }

    if(n>1)
    {
        cout<<"? 1 " << n-1 << '\n';
        cout.flush();
        for(int i=0;i<=n;i++)
        {
            ss[i].clear();
            for(int j=0;j<26;j++)
                sum[i][j]=0;
        }
        n--;

        for(int i=0;i<(n*(n+1))/2;i++)
        {
            string s;
            cin >> s;
            ss[s.size()].push_back(s);
        }
        for(auto y : ss[n][0])
            sum[n][y-'a']++;
        for(int i=n-1;i>=(n+1)/2;i--)
        {
            for(auto s : ss[i])
                for(auto c : s)
                    sum[i][c-'a']++;
            for(int j=n-1;j>i;j--)
            {
                sum[i][pos2[j][0]]+=(j-i+1);
                sum[i][pos2[j][1]]+=(j-i+1);
            }
            for(int j=0;j<26;j++)
            {
                sum[i][j]-=sum[n][j]*(n-i+1);
                sum[i][j]*=-1;
            }
            vector<int> ok;
            for(int j=0;j<26;j++)
                for(int jj=0;jj<sum[i][j];jj++)
                    ok.push_back(j);
            pos2[i][0]=ok[0];
            pos2[i][1]=ok[1];
        }

        n++;
        vector<char> res(n);
        if(n&1)
        {
            for(auto y : base)
                sum[n][y-'a']++;
            for(int i=n-1;i>=(n+1)/2;i--)
            {
                sum[n][pos[i][0]]--;
                sum[n][pos[i][1]]--;
            }
            for(int i=0;i<26;i++)
                if(sum[n][i])
                    res[n/2]='a'+i;
        }
        cout << "? 1 1\n";
        cout.flush();
        char c1;
        cin >> c1;
        res[0]=c1;
        int v=c1-'a';
        res[n-1]=pos[n-1][pos[n-1][0]==v]+'a';
        for(int i=0;i<(n/2)-1;i++)
        {
            res[n-2-i]=pos2[n-2-i][res[i]==(pos2[n-2-i][0]+'a')]+'a';
            res[i+1]=pos[n-2-i][res[n-2-i]==(pos[n-2-i][0]+'a')]+'a';
        }
        cout << "! ";
        for(int i=0;i<n;i++)
            cout << res[i];
        cout << '\n';
        cout.flush();
    }
    else
    {
        cout << "! " << ss[1][0] << '\n';
        cout.flush();
    }

//    for(int i=n-1;i>=(n+1)/2;i--)
//        cout << (char)(pos[i][0]+'a') << ' ' << (char)(pos[i][1]+'a') << '\n';
//    db("")
//    for(int i=n-2;i>=n/2;i--)
//        cout << (char)(pos2[i][0]+'a') << ' ' << (char)(pos2[i][1]+'a') << '\n';

    return 0;
}
/**
4
abcd
abc
bcd
ab
bc
cd
a
b
c
d
abc
ab
bc
a
b
c
a
**/