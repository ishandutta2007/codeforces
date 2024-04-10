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

int f[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        for(int i=0;i<26;i++)
            f[i]=0;
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        n=s.size();
        for(int i=0;i<n;i++)
            f[s[i]-'a']++;

        vector<char> res;
        for(int i=0;i<26;i++)
        {
            while(f[i]>=k)
            {
                res.push_back('a'+i);
                f[i]-=k;
                int ds=0;
                for(int j=0;j<26;j++)
                    if(f[j])
                        ds++;
                if(ds>1)
                {
                    for(int j=0;j<26;j++)
                    {
                        for(int kk=0;kk<f[j];kk++)
                            res.push_back('a'+j);
                        f[j]=0;
                    }
                }
            }
            if(!f[i])
                continue;
            int sum=0,last=-1;
            while(i<26 && sum<k)
            {
                if(f[i])
                    last=i;
                sum+=f[i];
                i++;
            }
            res.push_back('a'+last);
            break;
        }

        for(auto y : res)
            cout << y;
        cout << '\n';
    }

    return 0;
}