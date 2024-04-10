#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
vector<pii> points;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int x=1,y=1;
    for(int i=2;i<=n;i+=2){
        points.push_back({x,y});
        points.push_back({x+1,y});
        points.push_back({x+2,y});
        points.push_back({x+1,y+1});
        points.push_back({x+2,y+1});
        points.push_back({x+1,y-1});
        points.push_back({x+2,y-1});
        points.push_back({x+3,y});
        x+=4;
    }
    if(n%2){
        points.push_back({x,y});
        points.push_back({x+1,y});
        points.push_back({x+2,y});
        points.push_back({x+1,y-1});
        points.push_back({x+2,y-1});
        points.push_back({x+1,y+1});
    }
    else{
        points.push_back({x,y});
        points.push_back({x+1,y});
        points.push_back({x+1,y+1});
    }
    points.push_back({x+1,y+2});
    x+=1,y+=3;
    while(x>0){
        points.push_back({x,y});
        x-=1;
    }
    points.push_back({x,y});
    points.push_back({x,y-1});
    points.push_back({x,y-2});
    points.push_back({x,y-3});
    printf("%d\n",sz(points));
    for(auto ree:points){
        printf("%d %d\n",ree.first,ree.second);
    }
    return 0;
}