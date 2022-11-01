#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    map<int,int> stick;
    vector<int> usable;
    while(T--)
    {
        int n,temp;
        cin>>n;
        stick.erase(stick.begin(),stick.end());
        usable.erase(usable.begin(),usable.end());
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(stick.count(temp)&&stick[temp]!=0)
            {
                usable.push_back(temp);
                stick[temp]=0;
            }
            else stick[temp]++;
        }
        sort(usable.begin(),usable.end());
        pair<double,int > mina;
        mina.first=0;int pre=usable[0];
        for(int i=1;i<usable.size();i++)
        {
            double rate=(double)usable[i-1]/usable[i];
            if(rate>mina.first)
            {
                mina.first=rate;
                mina.second=i;
            }
        }
        printf("%d %d %d %d\n",usable[mina.second],usable[mina.second],usable[mina.second-1],usable[mina.second-1]);
    }
    return 0;
}