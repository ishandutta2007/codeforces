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
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

vector<int> manacher(const string &s)
{
	int n = 2 * s.length();
	vector<int> rad(n);

	for (int i = 0, j = 0, k; i < n; i += k, j = max(j - k, 0))
	{
		for (; i >= j && i + j + 1 < n
			&& s[(i - j) / 2] == s[(i + j + 1) / 2]; ++j);
		rad[i] = j;
		for (k = 1; i >= k &&
			rad[i] >= k && rad[i - k] != rad[i] - k; ++k)
			rad[i + k] = min(rad[i - k], rad[i] - k);
	}

	return rad;
}

bool is_pal(const vector<int> &rad, int b, int e)
{
	int n = rad.size() / 2;
	return b >= 0 && e < n && rad[b + e] >= e - b + 1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        vector<int> v=manacher(s);
        int n=s.size();

        int ma=0;
        while(ma<n/2 && s[ma]==s[n-1-ma])
            ma++;

        pii res=pii(1,0);
        for(int i=0;i<n;i++)
        {
            int cant=min(n-i-1,i);
            if(cant<=ma)
                res=max(res,pii(cant*2+1,i));
            else
            {
                int def=cant-ma;
                if(is_pal(v,i-def,i+def))
                    res=max(res,pii(cant*2+1,i));
            }
        }

        for(int i=0;i<n-1;i++)
        {
            int cant=min(n-i-1,i+1);
            if(cant<=ma)
                res=max(res,pii(cant*2,i));
            else
            {
                int def=cant-ma;
                int l=i-def+1;
                int r=i+def;
                if(is_pal(v,l,r))
                    res=max(res,pii(cant*2,i));
            }
        }

        if(res.first&1)
        {
            if(res.second>n-res.second-1)
            {
                reverse(s.begin(),s.end());
                res.second=n-res.second-1;
            }
            for(int i=0;i<res.second;i++)
                cout << s[i];
            cout << s[res.second];
            for(int i=0;i<res.second;i++)
                cout << s[res.second-i-1];
            cout << '\n';
        }
        else
        {
            if(res.second+1>n-res.second-1)
            {
                reverse(s.begin(),s.end());
                res.second=n-res.second-2;
            }

            for(int i=0;i<=res.second;i++)
                cout << s[i];
            for(int i=0;i<=res.second;i++)
                cout << s[res.second-i];
            cout << '\n';
        }
    }

    return 0;
}