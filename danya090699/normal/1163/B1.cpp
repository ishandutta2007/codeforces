#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int q[sz], q2[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    set <int> se;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        if(q[x])
        {
            q2[q[x]]--;
            if(q2[q[x]]==0) se.erase(q[x]);
        }
        q[x]++;
        if(q2[q[x]]==0) se.insert(q[x]);
        q2[q[x]]++;

        if(se.size()==1)
        {
            int x=*se.begin();
            if(x==1 or q2[x]==1) an=a+1;
        }
        if(se.size()==2)
        {
            auto it=se.begin();
            int x=*it;
            it++;
            int y=*it;

            if(y==x+1 and q2[y]==1) an=a+1;

            if(x==1 and q2[x]==1) an=a+1;
        }
    }
    cout<<an;
}