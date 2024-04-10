#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <limits>
using namespace std;
typedef long long ll;
int stairs[100000],elevators[100000];
int main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    int n,m,s,e,v,q;
    cin>>n>>m>>s>>e>>v;
    for(int i=0;i<s;++i){
        cin>>stairs[i];
    }
    for(int i=0;i<e;++i){
        cin>>elevators[i];
    }
    cin>>q;
    for(int i=0;i<q;++i){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int best=numeric_limits<int>::max();
        int* left_stair_ptr=lower_bound(stairs,stairs+s,y1,[](const int& x, const int& y){
            return x<y;
        });
        if(left_stair_ptr!=stairs+s){
            int left_stair=*left_stair_ptr;
            best=min(best,abs(left_stair-y1)+abs(left_stair-y2)+abs(x1-x2));
        }
        if(left_stair_ptr!=stairs){
            --left_stair_ptr;
            int left_stair=*left_stair_ptr;
            best=min(best,abs(left_stair-y1)+abs(left_stair-y2)+abs(x1-x2));
        }
        int* left_elevator_ptr=lower_bound(elevators,elevators+e,y1,[](const int& x, const int& y){
            return x<y;
        });
        if(left_elevator_ptr!=elevators+e){
            int left_elevator=*left_elevator_ptr;
            best=min(best,abs(left_elevator-y1)+abs(left_elevator-y2)+(abs(x1-x2)+(v-1))/v);
        }
        if(left_elevator_ptr!=elevators){
            --left_elevator_ptr;
            int left_elevator=*left_elevator_ptr;
            best=min(best,abs(left_elevator-y1)+abs(left_elevator-y2)+(abs(x1-x2)+(v-1))/v);
        }
        if(x1==x2){
            best=min(best,abs(y1-y2));
        }
        cout<<best<<'\n';
    }
}