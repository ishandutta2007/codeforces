#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=2021;
int arr[MAXN],ans[MAXN*5/2];
int f(int x){
    for(int i=0;true;++i){
        if(arr[i]==x)return i;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    for(int c=0;c<t;++c){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        {
            int i;
            for(i=0;i<n;++i){
                if(((arr[i]^i)&1)==0){
                    cout<<"-1\n";
                    break;
                }
            }
            if(i<n)continue;
        }
        int* ans_end=ans;
        for(int j=n;j>1;j-=2){
            int q;
            q=f(j);
            if(q){
                *ans_end++=q+1;
                reverse(arr,arr+q+1);
            }
            q=f(j-1);
            if(q-1){
                *ans_end++=q;
                reverse(arr,arr+q);
            }
            *ans_end++=q+2;
            reverse(arr,arr+q+2);
            *ans_end++=3;
            reverse(arr,arr+3);
            *ans_end++=j;
            reverse(arr,arr+j);
        }
        cout<<ans_end-ans<<'\n';
        for(int* it=ans;it!=ans_end;++it){
            if(it!=ans)cout<<' ';
            cout<<*it;
        }
        cout<<'\n';
    }
}