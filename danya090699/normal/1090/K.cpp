#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e6+10;
char buf[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    map <pair <string, int>, vector <int> > ma;
    for(int a=0; a<n; a++)
    {
        string s, t;
        scanf("%s", buf);
        int yk=0, mask=0;
        while(buf[yk]) s.push_back(buf[yk]), yk++;
        scanf("%s", buf);
        yk=0;
        while(buf[yk])
        {
            mask|=(1<<(buf[yk]-'a'));
            t.push_back(buf[yk]), yk++;
        }
        int q=s.size();
        while(q)
        {
            int sy=s[q-1]-'a';
            if((mask&(1<<sy))==0) break;
            q--;
        }
        s=s.substr(0, q);
        ma[{s, mask}].push_back(a);
    }
    cout<<ma.size()<<"\n";
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        vector <int> &sp=(*it).second;
        printf("%d ", sp.size());
        for(int a=0; a<sp.size(); a++) printf("%d ", sp[a]+1);
        printf("\n");
    }
}