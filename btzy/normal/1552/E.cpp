#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=100;
int arr[MAXN*MAXN];
int handles[MAXN][MAXN];
pair<int,int> ans[MAXN];
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int handles_ct[MAXN];
    fill_n(handles_ct,n,0);
    for(int i=0;i<n*k;++i){
        cin>>arr[i];
        --arr[i];
        handles[arr[i]][handles_ct[arr[i]]++]=i;
    }
    /*for(int i=0;i<n;++i){
        for(int j=0;j<k;++j){
            cout<< ' '<<handles[i][j];
        }
        cout<<'\n';
    }*/
    fill_n(handles_ct,n,1);
    int magic=(n+(k-2))/(k-1);
    for(int i=0;i<n;){
        int cutoff=-1;
        for(int ii=0;i<n&&ii<magic;++ii,++i){
            int best=-1;
            for(int j=0;j<n;++j){
                if(ans[j].second==0){
                    if(best==-1||handles[j][handles_ct[j]]<handles[best][handles_ct[best]]){
                        best=j;
                    }
                }
            }
            //cout<<"T "<<best<<' '<<handles_ct[best]<<'\n';
            ans[best].first=handles[best][handles_ct[best]-1];
            cutoff=ans[best].second=handles[best][handles_ct[best]];
        }
        if(cutoff==-1)break;
        for(int j=0;j<n;++j){
            if(ans[j].second==0){
                if(handles[j][handles_ct[j]-1]<=cutoff)++handles_ct[j];
            }
        }
    }
    for(int i=0;i<n;++i){
        cout<<ans[i].first+1<<' '<<ans[i].second+1<<'\n';
    }
}