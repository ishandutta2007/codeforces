#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int x;
    cin>>x;
    vector <int> ch, an;
    while(x) ch.push_back(x&1), x>>=1;
    while(ch.size())
    {
        int a;
        for(a=0; ch[a]==0; a++) ch[a]=1;
        an.push_back(a);
        bool fo=0;
        for(a=0; a<ch.size(); a++)
        {
            if(ch[a]) ch[a]=0;
            else
            {
                ch[a]=1;
                fo=1;
                break;
            }
        }
        if(fo==0) break;
    }
    cout<<an.size()*2-1<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
}