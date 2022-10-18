#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=505;

pair<int,int> x[maxn];
int n;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i].first,x[i].second=i;
    sort(x+1,x+1+n);
    int cur=0,p=1;
    pair<int,int> ans={0,0};int ansi=-1;
    for(int i=1;i<=n;i++){
        cur+=x[i].first-i+1;
        if(cur==0){
            if(p!=i){
                int u=x[i].first-x[p].first;
                if(u>ansi){
                    ansi=u;ans={x[i].second,x[p].second};
                }
            }
            p=i+1;
        }
    }
    cout<<"! "<<ans.first<<' '<<ans.second;
    return 0;
}