#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
map<int,int> cnt;
vector<int> all;
int task[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    int top=0;
    for(int i=0,temp;i<n;i++)
    {
        scanf("%d",&temp);
        cnt[temp]++;
        all.push_back(temp);
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(int i=0;i<all.size();i++)
    {
        task[i]=cnt[all[i]];
        top=max(top,task[i]);
    }
    sort(task,task+all.size());
    int ans=0;
    for(int base=1;base<=200000;base++)
    {
        int now=0;
        int temp=0;
        int num=base;
        while(num<=top&&now<=all.size())
        {
            temp+=num;
            now=lower_bound(task+now,task+all.size(),num)-task;
            now++;
            if(now>all.size()) { temp-=num;break;}
            //cout<<now<<" "<<temp<<endl;
            num*=2;
        }
        ans=max(ans,temp);
    }
    printf("%d\n",ans);
    
}