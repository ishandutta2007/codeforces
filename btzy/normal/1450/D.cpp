#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=300000;
int arr[MAXN];
bool flags[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct!=tc;++ct){
        int n;
        cin>>n;
        fill_n(flags,n,false);
        bool is_permutation = true;
        for (int i=0;i<n;++i){
            cin>>arr[i];
            --arr[i];
            if(arr[i]<n){
                if(flags[arr[i]]){
                    is_permutation=false;
                }
                else{
                    flags[arr[i]]=true;
                }
            }
            else{
                is_permutation=false;
            }
        }
        int lowest_saddle=INT_MAX;
        for(int i=1;i<n-1;++i){
            if(arr[i]<=arr[i-1]&&arr[i]<=arr[i+1]){
                lowest_saddle=min(lowest_saddle, arr[i]);
            }
        }
        if(lowest_saddle==INT_MAX){
            lowest_saddle=INT_MIN;
            for(int i=0;i<n;++i){
                lowest_saddle=max(lowest_saddle,arr[i]);
            }
        }
        int i1=0,i2=n-1;
        while(arr[i1]<lowest_saddle||arr[i2]<lowest_saddle){
            /*if(arr[i1]>=lowest_saddle){
                arr[i1]=lowest_saddle;
                break;
            }
            if(arr[i2]>=lowest_saddle){
                arr[i2]=lowest_saddle;
                break;
            }*/
            if(arr[i1]==arr[i2])break;
            if(arr[i1]<arr[i2]){
                ++i1;
                continue;
            }
            else{
                --i2;
                continue;
            }
        }
        if(arr[i1]>lowest_saddle)arr[i1]=lowest_saddle;
        if(arr[i2]>lowest_saddle)arr[i2]=lowest_saddle;
        //cout<<"DBG"<<i1<<' '<<i2<<' '<<lowest_saddle<<endl;
        for (int i=i1;i<i2;++i){
            if(i==i1)cout<<is_permutation;
            else cout<<'0';
        }
        int tally=i1+(n-i2);
        while(i1>0||i2<n){
            int e1=i1>0?arr[i1-1]:INT_MIN;
            int e2=i2<n?arr[i2]:INT_MIN;
            int val = max(e1, e2);
            cout<<(val<tally--);
            if(e1<e2){
                ++i2;
            }
            else{
                --i1;
            }
        }
        cout<<'\n';
    }
}