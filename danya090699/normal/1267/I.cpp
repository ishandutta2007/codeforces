#include <bits/stdc++.h>
using namespace std;
vector <int> sp[2];
void ins(int x)
{
    int i=0;
    if(sp[0].size()>sp[1].size()) i=1;
    sp[i].push_back(x);
    for(int a=sp[i].size()-1; a; a--)
    {
        cout<<"? "<<sp[i][a]<<" "<<sp[i][a-1]<<"\n";
        char re;
        cin>>re;
        if(re=='>') swap(sp[i][a], sp[i][a-1]);
        else break;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        cin>>n;
        for(int a=1; a<=n*2; a++)
        {
            ins(a);
            if(sp[0].size()+sp[1].size()>n)
            {
                cout<<"? "<<sp[0].back()<<" "<<sp[1].back()<<"\n";
                char re;
                cin>>re;
                if(re=='>') sp[1].pop_back();
                else sp[0].pop_back();
            }
        }
        cout<<"!"<<"\n";
        sp[0].clear();
        sp[1].clear();
    }
}