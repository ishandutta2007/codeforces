#include<bits/stdc++.h>
using namespace std;
vector<bool>sol;
int initial;
int h1,a1,c1;
int h2,a2;
int main()
{
    cin>>h1>>a1>>c1;
    cin>>h2>>a2;
    while(1)
    {
        if(h2-a1<=0)///STRIKE
        {
            sol.push_back(0);
            break;
        }
        if(h1-a2<=0)///HEAL
        {
            sol.push_back(1);
            h1+=c1;
            h1-=a2;
            continue;
        }
        ///STRIKE
        sol.push_back(0);
        h2-=a1;
        h1-=a2;
        if(h2<=0)
            break;
    }
    cout<<sol.size()<<"\n";
    for(int i=0;i<sol.size();i++)
        if(sol[i]==0)
            cout<<"STRIKE\n";
        else
            cout<<"HEAL\n";
    return 0;
}
/**
STRIKE = 0
HEAL   = 1
**/