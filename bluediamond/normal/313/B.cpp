#include <bits/stdc++.h>

using namespace std;

int main()
{
    { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
    string a; cin>>a;
    int n=a.size();
    vector<int>cnt(n);
    cnt[0]=0;
    for(int i=1;i<n;i++)
    {
        cnt[i]=cnt[i-1]; if(a[i]==a[i-1]) cnt[i]++;
    }
    int q; cin>>q;
    while(q--)
    {
        int st,dr; cin>>st>>dr; st--; dr--;
        cout<<cnt[dr]-cnt[st]<<"\n";
    }
}