#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int who[30];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a,b;
    cin>>a>>b;
    for(int i=0;i<26;i++)
        who[i]=-1;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(who[b[i]-'a']!=-1 && who[b[i]-'a']!=a[i]-'a')
        {
            cout<<"-1\n";
            return 0;
        }
        who[b[i]-'a']=a[i]-'a';
    }
    int cnt=0;
    set< pair<int,int> >s;
    for(int i=0;i<26;i++)
    {
        if(who[i]==-1 || who[i]==i) continue;
      //  cout<<char('a'+i)<<" , "<<who[i]<<"\n";
        if(who[who[i]]!=-1 && who[who[i]]!=i)
        {
            cout<<"-1\n";
            return 0;
        }
        s.insert(make_pair(min(i,who[i]),max(i,who[i])));
    }
    cout<<s.size()<<"\n";
    for(auto itr:s)
    {
        cout<<char('a'+itr.first)<<" "<<char('a'+itr.second)<<"\n";
    }
    return 0;
}
/**


**/