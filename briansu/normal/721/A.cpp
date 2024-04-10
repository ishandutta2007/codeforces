#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-8;
const ll INF=ll(1e18);
int main()
{
    int n;
    cin>>n;
    vector<int> ans;
    int cnt=0;
    string s;
    cin>>s;
    int tmp=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B')tmp++;
        else
        {
            if(tmp)
            {
                ans.push_back(tmp);
                tmp=0;
                cnt++;
            }
        }
    }
    if(tmp)
    {
        ans.push_back(tmp);
        tmp=0;
        cnt++;
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        cout<<(i==0?"":" ")<<ans[i];
        if(i==cnt-1)cout<<endl;
    }

}