#include<bits/stdc++.h>
using namespace std;
bool judge(int x)
{
    bool st=0;
    for(int i=21;i>=0;i--)
    {
        if(x&(1<<i)) st=1;
        if(st&&((x&(1<<i))==0)) return false;
    }
    return true;
}
int main()
{
    int x;
    cin>>x;
    int t=0;
    vector<int> ans;
    for(int i=20;i>=0;i--)
    {
        if((x&(1<<i))==0) 
        {
            ans.push_back(i+1);
            t++;
            x^=(1<<(i+1))-1;
            if(judge(x)) break;
            x+=1;
            t++;
            if(judge(x)) break;
        }
    }
    cout<<t<<endl;
    for(auto p:ans) cout<<p<<" ";
    cout<<endl;
}