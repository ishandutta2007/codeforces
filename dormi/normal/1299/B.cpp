#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MAXN=1e5+1;
pair<lli,lli> points[MAXN];
map<pair<pair<lli,lli>,lli>,int> yeet;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>points[i].first>>points[i].second;
    }
    bool work=true;
        lli rise=points[0].second-points[n-1].second;
        lli run=points[0].first-points[n-1].first;
        lli dist=(points[0].first-points[n-1].first)*(points[0].first-points[n-1].first)+(points[0].second-points[n-1].second)*(points[0].second-points[n-1].second);
        lli k=__gcd(abs(rise),abs(run));
        rise/=k,run/=k;
            if(rise==0){
                run=1;
            }
            else if(run==0)rise=1;
        if(run<0){
            rise*=-1,run*=-1;
        }
        yeet[{{rise,run},dist}]+=1;
        for(int i=1;i<n;i++){
             rise=points[i].second-points[i-1].second;
             run=points[i].first-points[i-1].first;
             dist=(points[i].first-points[i-1].first)*(points[i].first-points[i-1].first)+(points[i].second-points[i-1].second)*(points[i].second-points[i-1].second);
             k=__gcd(abs(rise),abs(run));
            rise/=k,run/=k;
            if(rise==0){
                run=1;
            }
            else if(run==0)rise=1;
            if(run<0){
                rise*=-1,run*=-1;
            }
            yeet[{{rise,run},dist}]+=1;
        }
        for(auto x:yeet){
            if(x.second==1)work=false;
        }
        if(work){
            printf("YES\n");
        }
        else printf("NO\n");

    return 0;
}