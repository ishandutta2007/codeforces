#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, left=0;
    cin>>n;
    vector <int> sp, sp2;
    int q[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &q[a]);
        if(q[a]>1) left+=q[a], sp.push_back(a);
        else sp2.push_back(a);
    }
    if(sp.size())
    {
        left-=2*(sp.size()-1);
        if(n-sp.size()<=left)
        {
            int di=sp.size()-1;
            vector <pair <int, int> > re;
            for(int a=0; a+1<sp.size(); a++)
            {
                q[sp[a]]--, q[sp[a+1]]--;
                re.push_back({sp[a], sp[a+1]});
            }

            if(sp2.size())
            {
                q[sp[0]]--, di++;
                re.push_back({sp[0], sp2.back()});
                sp2.pop_back();
            }
            if(sp2.size())
            {
                q[sp.back()]--, di++;
                re.push_back({sp.back(), sp2.back()});
                sp2.pop_back();
            }
            int yk=0;
            while(sp2.size())
            {
                while(q[sp[yk]]==0) yk++;
                re.push_back({sp[yk], sp2.back()});
                q[sp[yk]]--;
                sp2.pop_back();
            }
            cout<<"YES "<<di<<"\n"<<n-1<<"\n";
            for(int a=0; a<n-1; a++)
            {
                cout<<re[a].first+1<<" "<<re[a].second+1<<"\n";
            }
        }
        else cout<<"NO";
    }
    else cout<<"NO";
}