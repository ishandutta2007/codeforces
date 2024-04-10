#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+1;
typedef tuple<int,int,int,int> Rect;
vector<pair<Rect,Rect> > key_query;
int n;
int query(Rect rect){
    int x1,y1,x2,y2;
    tie(x1,y1,x2,y2) = rect;
    printf("? %d %d %d %d\n",x1,y1,x2,y2);
    fflush(stdout);
    int ans;
    scanf("%d",&ans);
    return ans&1;
}
vector<pair<int,int> > ans;
void answer(){
    printf("!");
    for (pair<int,int> p : ans){
        int x,y;
        tie(x,y) = p;
        printf(" %d %d",x,y);
    }
    fflush(stdout);
}
void gao(Rect rect){
    int x1,y1,x2,y2;
    tie(x1,y1,x2,y2) = rect;
    int xl = x1;
    int xr = x2;
    int ansx = -1,ansy = -1;
    while (xr - xl > 1){
        int mid = xl + xr >> 1;
        Rect temp = make_tuple(x1,y1,mid,y2);
        if (query(temp)){
            xr = mid;
        }else{
            xl = mid;
        }
    }
    Rect temp_l = make_tuple(x1,y1,xl,y2);
    if (query(temp_l)){
        ansx = xl;
    }else{
        ansx = xr;
    }
    int yl = y1;
    int yr = y2;
    while (yr - yl > 1){
        int mid = yl + yr >> 1;
        Rect temp = make_tuple(ansx,y1,ansx,mid);
        if (query(temp)){
            yr = mid;
        }else{
            yl = mid;
        }
    }
    temp_l = make_tuple(ansx,yl,ansx,yl);
    if (query(temp_l)){
        ansy = yl;
    }else{
        ansy = yr;
    }
    ans.push_back(make_pair(ansx,ansy));
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n-1;i++){
        key_query.push_back(make_pair(make_tuple(1,1,i,n),make_tuple(i+1,1,n,n)));
        key_query.push_back(make_pair(make_tuple(1,1,n,i),make_tuple(1,i+1,n,n)));
    }
    random_shuffle(key_query.begin(),key_query.end());
    for (pair<Rect,Rect>pr : key_query){
        if (query(pr.first) && query(pr.second)){
            gao(pr.first);
            gao(pr.second);
            answer();
            return 0;
        }
    }
    assert(0);
    return 0;
}