#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
pair<int,int> category[200005];
vector<int> desire;
map<int,int> occur;
priority_queue<pair<int,int> > available;
ll ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>category[i].first;
        occur[category[i].first]++;
    }
    for(int i=0;i<n;i++){
        cin>>category[i].second;
    }
    sort(category,category+n);
    {
        int cur=occur.begin()->first;
        map<int,int>::iterator it;
        while(true){
            desire.push_back(cur);
            if(occur[cur]>1){
                occur[cur+1]+=occur[cur]-1;
            }
            it=occur.lower_bound(cur+1);
            if(it==occur.end())break;
            cur=it->first;
        }
    }
    assert(desire.size()==n);
    for(int i=0,it=0;i<n;i++){
        while(it<n&&desire[i]==category[it].first){
            available.push(make_pair(category[it].second,category[it].first));
            it++;
        }
        int cost=available.top().first;
        int diff=available.top().second;
        available.pop();
        ans+=(ll)cost*(desire[i]-diff);
    }
    assert(available.empty());
    cout<<ans<<endl;

    return 0;
}