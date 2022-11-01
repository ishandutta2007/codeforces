#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> teleporters(n);
    for(int i=0;i<n;i++) for(int j=0;j<2;j++) cin >> teleporters[i][j];
    vector<array<int,3>> quests(m);
    for(int i=0;i<m;i++) cin >> quests[i][1] >> quests[i][2] >> quests[i][0];
    sort(quests.begin(),quests.end());
    const int inf=2000000000;
    vector dp1(m+1,vector(1<<n,inf));
    vector dp2(m,vector(1<<n,-1));
    auto chmin=[&](int &a,int b){a=min(a,b);};
    auto chmax=[&](int &a,int b){a=max(a,b);};
    auto updone=[&](int cnt,int mask,int t){chmin(dp1[cnt][mask],t);};
    auto updtwo=[&](int quest,int mask,int val){chmax(dp2[quest][mask],val);};
    for(int i=0;i<n;i++) updone(0,(1<<i),0);
    for(int i=0;i<m;i++) updtwo(i,0,1);
    vector closest_teleporter(n,vector(1<<n,inf));
    for(int i=0;i<n;i++)
    {
        for(int mask=1;mask<(1<<n);mask++)
        {
            int &best=closest_teleporter[i][mask];
            for(int j=0;j<n;j++) if(mask&(1<<j)) chmin(best,abs(teleporters[i][0]-teleporters[j][0])+abs(teleporters[i][1]-teleporters[j][1]));
        }
    }
    vector closest_quest(m,vector(1<<n,inf));
    for(int i=0;i<m;i++)
    {
        for(int mask=1;mask<(1<<n);mask++)
        {
            int &best=closest_quest[i][mask];
            for(int j=0;j<n;j++) if(mask&(1<<j)) chmin(best,abs(quests[i][1]-teleporters[j][0])+abs(quests[i][2]-teleporters[j][1]));
        }
    }
    auto dqq=[&](int i,int j){return (abs(quests[i][1]-quests[j][1])+abs(quests[i][2]-quests[j][2]));};
    auto dqt=[&](int i,int j){return (abs(quests[i][1]-teleporters[j][0])+abs(quests[i][2]-teleporters[j][1]));};
    int res=0;
    for(int mask=0;mask<(1<<n);mask++)
    {
        //process bounces within mask
        for(int quest=0;quest<m;quest++)
        {
            //try updating from left
            for(int cnt=0;cnt<=m;cnt++)
            {
                if(dp1[cnt][mask]==inf) continue;
                if(dp1[cnt][mask]+closest_quest[quest][mask]<=quests[quest][0]) updtwo(quest,mask,cnt+1);
            }
            //now update from here
            if(dp2[quest][mask]==-1) continue;
            for(int j=quest+1;j<m;j++) if(quests[quest][0]+dqq(quest,j)<=quests[j][0]) updtwo(j,mask,dp2[quest][mask]+1);
            for(int i=0;i<n;i++) if(mask&(1<<i)) updone(dp2[quest][mask],mask,quests[quest][0]);
        }
        //extend from mask
        for(int cnt=0;cnt<=m;cnt++)
        {
            if(dp1[cnt][mask]==inf) continue;
            for(int i=0;i<n;i++) if((mask&(1<<i))==0) updone(cnt,mask|(1<<i),dp1[cnt][mask]+closest_teleporter[i][mask]);
        }
        for(int quest=0;quest<m;quest++)
        {
            if(dp2[quest][mask]==-1) continue;
            for(int i=0;i<n;i++) if((mask&(1<<i))==0) updone(dp2[quest][mask],mask|(1<<i),quests[quest][0]+dqt(quest,i));
            res=max(res,dp2[quest][mask]);
        }
    }
    cout << res << "\n";
    return 0;
}