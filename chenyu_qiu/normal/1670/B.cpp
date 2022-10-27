#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int k;
        cin>>k;
        bool sp[26];
        for(int i=0;i<26;i++)
        {
            sp[i]=0;
        }
        for(int i=0;i<k;i++)
        {
            char c;
            cin>>c;
            sp[c-'a']=1;
        }
        int best=0;
        for(int i=n-1;i>=0;)
        {
            if(sp[s[i]-'a']==1)
            {
                // cout<<s[i]<<endl;
                i--;
                int ans=0;
                while(sp[s[i]-'a']==0&&i>=0)
                {
                    // cout<<s[i]<<"=0"<<endl;
                    i--;
                    ans++;
                }
                if(i>=0)
                {
                    ans++;
                }
                best=max(best,ans);                
            }
            else
            {
                i--;
            }
        }
        cout<<best<<'\n';
    }
}