#include <bits/stdc++.h>

using namespace std;

void put(string s,int a[])
{
        reverse(s.begin(),s.end());
        int p=0;
        for(auto &x:s)
        {
                a[p]+=(x-'a');
                p++;
        }
}

const int N=(int)2e5+7;

int n;
int a[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        string f,s;
        cin>>f>>s;
        put(f,a);
        put(s,a);
        for(int i=0;i<n;i++)
        {
                if(a[i]>=26)
                {
                        a[i+1]++;
                        a[i]-=26;
                }
        }
        for(int i=n;i>=0;i--)
        {
                if(a[i]%2==1)
                {
                        a[i-1]+=26;
                }
                a[i]/=2;
        }
        for(int i=n-1;i>=0;i--)
        {
                cout<<char('a'+a[i]);
        }
        cout<<"\n";
        return 0; }