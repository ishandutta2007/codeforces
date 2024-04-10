#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool lib[10];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        /// freopen("__input__","r",stdin);

        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int j=0;j<=9;j++)
                lib[j]=1;
        for(auto &it : s)
        {
                if(it=='L')
                {
                        for(int j=0;j<=9;j++)
                                if(lib[j])
                                {
                                        lib[j]=0;
                                        break;
                                }
                        continue;
                }
                if(it=='R')
                {
                        for(int j=9;j>=0;j--)
                                if(lib[j])
                                {
                                        lib[j]=0;
                                        break;
                                }
                        continue;
                }
                lib[it-'0']=1;
        }
        for(int i=0;i<=9;i++)
                cout<<1-lib[i];
        cout<<"\n";

        return 0;
}
/**

**/