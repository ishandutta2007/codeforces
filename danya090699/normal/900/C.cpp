#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int q[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    set <int> se;
    for(int a=1; a<=n; a++)
    {
        int x;
        cin>>x;
        if(se.size()>0)
        {
            set <int>::iterator it=se.end();
            it--;
            if((*it)>x)
            {
                if(it==se.begin()) q[*it]++;
                else
                {
                    it--;
                    if((*it)<x) q[*(++it)]++;
                }
            }
            else q[x]--;
        }
        else q[x]--;
        se.insert(x);
    }
    int an=1;
    for(int a=2; a<=n; a++) if(q[an]<q[a]) an=a;
    cout<<an;
}