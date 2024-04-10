#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int n;

const int maxn=205;

vector<pair<int,int> > v[2];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        v[(i+j)&1].push_back({i,j});
    }
    for(int i=1;i<=n*n;i++){
        int a;
        cin>>a;
        if(a==3){
            if(!v[0].empty()){
                cout<<1<<' '<<v[0].back().first<<' '<<v[0].back().second<<endl;
                v[0].pop_back();
            }else{
                cout<<2<<' '<<v[1].back().first<<' '<<v[1].back().second<<endl;
                v[1].pop_back();
            }
        }else if(a==2){
            if(!v[0].empty()){
                cout<<1<<' '<<v[0].back().first<<' '<<v[0].back().second<<endl;
                v[0].pop_back();
            }else{
                cout<<3<<' '<<v[1].back().first<<' '<<v[1].back().second<<endl;
                v[1].pop_back();
            }
        }else{
            if(!v[1].empty()){
                cout<<2<<' '<<v[1].back().first<<' '<<v[1].back().second<<endl;
                v[1].pop_back();
            }else{
                cout<<3<<' '<<v[0].back().first<<' '<<v[0].back().second<<endl;
                v[0].pop_back();
            }
        }
    }
    return 0;
}