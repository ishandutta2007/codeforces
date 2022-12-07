#include <bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    string an;
    cout<<"? 1 1"<<endl;
    cin>>an;
    cout<<"? 1 "<<n<<endl;
    multiset <vector <char> > se[n+1];
    for(int a=0; a<((n+1)*n)/2; a++)
    {
        string s;
        cin>>s;
        vector <char> ve;
        for(int b=0; b<s.size(); b++) ve.push_back(s[b]);
        sort(ve.begin(), ve.end());
        se[ve.size()].insert(ve);
    }
    if(n>1)
    {
        cout<<"? 2 "<<n<<endl;
        for(int a=0; a<(n*(n-1))/2; a++)
        {
            string s;
            cin>>s;
            vector <char> ve;
            for(int b=0; b<s.size(); b++) ve.push_back(s[b]);
            sort(ve.begin(), ve.end());
            se[ve.size()].erase(se[ve.size()].find(ve));
        }
        for(int a=2; a<=n; a++)
        {
            vector <char> ve=*se[a].begin();
            int q[26];
            for(int b=0; b<26; b++) q[b]=0;
            for(int b=0; b<a; b++) q[ve[b]-'a']++;
            for(int b=0; b<a-1; b++) q[an[b]-'a']--;
            for(int b=0; b<26; b++)
            {
                if(q[b]) an.push_back('a'+b);
            }
        }
    }
    cout<<"! "<<an<<endl;
}