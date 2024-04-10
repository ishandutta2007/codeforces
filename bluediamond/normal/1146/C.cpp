#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int t;
        cin>>t;
        while(t--)
        {
                int n;
                cin>>n;
                int ans=0;
                int cntop=0;
                for(int bit=0;bit<9;bit++)
                {
                        vector <int> a,b;
                        for(int i=1;i<=n;i++)
                        {
                                if((i-1)&(1<<bit)) a.push_back(i);
                                else b.push_back(i);
                        }
                        if(a.size()==0 || b.size()==0) continue;
                        cout<<a.size()<<" "<<b.size()<<" ";
                        for(auto &x:a) cout<<x<<" ";
                        for(auto &x:b) cout<<x<<" ";
                        cout<<endl;
                        int cur;
                        cin>>cur;
                        ans=max(ans,cur);
                        cntop++;
                        if(cntop>9)
                        {
                                while(1)
                                {
                                        
                                }
                        }
                }
                cout<<"-1 "<<ans<<endl;
        }
        return 0;
}
/**

5
5 4
5 3
4 1
4 2

**/