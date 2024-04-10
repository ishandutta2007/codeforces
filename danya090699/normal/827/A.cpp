//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define iter set <int>::iterator
using namespace std;
const int sz=2e6+10;
char an[sz];
set <int> se;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, le=0;
    cin>>n;
    for(int a=sz-1; a>=0; a--)
    {
        an[a]='a';
        se.insert(se.begin(), a);
    }
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        int q, m=s.size();
        scanf("%d", &q);
        for(int b=0; b<q; b++)
        {
            int st;
            scanf("%d", &st);
            st--;
            iter it=se.lower_bound(st), it2;
            it2=it;
            while(it!=se.end())
            {
                if(*it<st+m)
                {
                    an[*it]=s[*it-st];
                    it++;
                }
                else break;
            }
            se.erase(it2, it);
            le=max(le, st+m);
        }
    }
    for(int a=0; a<le; a++) printf("%c", an[a]);
}