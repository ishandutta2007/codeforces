#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <char> ar[n];
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        for(int b=0; b<s.size(); b++) ar[a].push_back(s[b]);
    }
    for(int a=n-2; a>=0; a--)
    {
        int m1=ar[a].size(), m2=ar[a+1].size(), fo=0;
        for(int b=0; b<min(m1, m2); b++)
        {
            if(ar[a][b]!=ar[a+1][b])
            {
                if(ar[a][b]>ar[a+1][b])
                {
                    while(ar[a].size()>b) ar[a].pop_back();
                }
                fo=1;
                break;
            }
        }
        if(fo==0)
        {
            if(ar[a].size()>ar[a+1].size())
            {
                while(ar[a].size()>ar[a+1].size()) ar[a].pop_back();
            }
        }
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<ar[a].size(); b++) cout<<ar[a][b];
        cout<<"\n";
    }
}