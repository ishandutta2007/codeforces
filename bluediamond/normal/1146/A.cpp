#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        int cnta=0;
        for(int i=0;i<s.size();i++)
        {
                if(s[i]=='a')
                {
                        cnta++;
                }
        }
        int total=s.size();
        while(cnta*2<=total)
        {
                total--;
        }
        cout<<total<<"\n";
        return 0;
}
/**

**/