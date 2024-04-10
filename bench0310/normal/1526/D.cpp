#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    map<char,int> m={{'A',0},{'N',1},{'O',2},{'T',3}};
    string h="ANOT";
    while(t--)
    {
        string s;
        cin >> s;
        int n=s.size();
        vector<int> a(n,0);
        vector<int> c(4,0);
        for(int i=0;i<n;i++)
        {
            a[i]=m[s[i]];
            c[a[i]]++;
        }
        vector<vector<ll>> score(4,vector<ll>(4,0));
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(i==j) continue;
                int cnt=0;
                for(int x:a)
                {
                    if(x==i) score[i][j]+=cnt;
                    if(x==j) cnt++;
                }
            }
        }
        ll opt=-1;
        vector<int> best;
        vector<int> p={0,1,2,3};
        do
        {
            ll now=0;
            for(int i=0;i<4;i++)
            {
                for(int j=i+1;j<4;j++)
                {
                    now+=score[p[i]][p[j]];
                }
            }
            if(now>opt)
            {
                opt=now;
                best=p;
            }
        }while(next_permutation(p.begin(),p.end()));
        string res(n,'$');
        int idx=0;
        for(int x:best) for(int i=0;i<c[x];i++) res[idx++]=h[x];
        cout << res << "\n";
    }
    return 0;
}