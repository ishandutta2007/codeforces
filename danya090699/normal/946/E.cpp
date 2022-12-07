#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        string s;
        cin>>s;
        int n=s.size();
        bool pref[n+1][10], fo=0;
        for(int a=0; a<10; a++) pref[0][a]=0;
        for(int a=1; a<=n; a++)
        {
            for(int b=0; b<10; b++) pref[a][b]=pref[a-1][b];
            pref[a][s[a-1]-'0']^=1;
        }
        for(int a=n-1; a>=0; a--)
        {
            int zi=s[a]-'0';
            for(int b=zi-1; b>=0; b--)
            {
                if(a==0 and b==0)
                {
                    int q=n-1;
                    q-=q%2;
                    for(int c=0; c<q; c++) cout<<9;
                    cout<<"\n";
                    fo=1;
                    break;
                }
                else
                {
                    pref[a][b]^=1;
                    int q=0;
                    for(int c=0; c<10; c++) q+=pref[a][c];
                    if(a+1+q<=n)
                    {
                        char sy='0'+b;
                        string re=s.substr(0, a)+sy;
                        int le=n-(a+1+q);
                        for(int c=0; c<le; c++) re.push_back('9');
                        for(int c=9; c>=0; c--) if(pref[a][c]) re.push_back('0'+c);
                        cout<<re<<"\n";
                        fo=1;
                        break;
                    }
                    pref[a][b]^=1;
                }
            }
            if(fo) break;
        }
    }
}