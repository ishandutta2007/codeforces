#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=200000;
int arr[MAXN];
vector<int> parents[MAXN];
vector<int> sad;
bool is_sad[MAXN];
vector<int> rebind;
bool is_rebind[MAXN];
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>arr[i];
            arr[i]--;
            parents[arr[i]].push_back(i);
        }
        for(int i=0;i<n;++i){
            if(parents[i].empty()){
                sad.push_back(i);
                is_sad[i]=true;
            }
        }
        for(int i=0;i<n;++i){
            if(parents[i].size()>1){
                partition(parents[i].begin(),parents[i].end(),[](int x){
                    return !is_sad[x];
                });
                for(size_t j=0;j+1<parents[i].size();++j){
                    rebind.push_back(parents[i][j]);
                    is_rebind[parents[i][j]]=true;
                }
            }
        }
        sort(sad.begin(),sad.end(),[](int a, int b){
            if(is_rebind[a]!=is_rebind[b])return is_rebind[a]>is_rebind[b];
            return a<b;
        });
        sort(rebind.begin(),rebind.end(),[](int a, int b){
            if(is_sad[a]!=is_sad[b])return is_sad[a]>is_sad[b];
            return a<b;
        });
        int num_intersection=0;
        for(int i=0;i<n;++i){
            if(is_sad[i]&&is_rebind[i])++num_intersection;
        }
        if(num_intersection==1)++num_intersection;
        if(num_intersection>0){
            for(int i=0;i+1<num_intersection;++i){
                arr[rebind[i]]=sad[i+1];
            }
            arr[rebind[num_intersection-1]]=sad[0];
        }
        for(int i=num_intersection;i<sad.size();++i){
            arr[rebind[i]]=sad[i];
        }
        cout<<n-sad.size()<<'\n';
        for(int i=0;i<n;++i){
            if(i>0)cout<<' ';
            cout<<arr[i]+1;
        }
        cout<<'\n';
        for(int i=0;i<n;++i)parents[i].clear();
        sad.clear();
        rebind.clear();
        for(int i=0;i<n;++i){
            is_sad[i]=false;
        }
        for(int i=0;i<n;++i){
            is_rebind[i]=false;
        }
    }
}