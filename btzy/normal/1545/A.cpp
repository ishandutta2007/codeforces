#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=100000;
pair<int, bool> arr[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>arr[i].first;
            arr[i].second=i%2;
        }
        sort(arr,arr+n,[](const pair<int, bool>& a, const pair<int, bool>& b){
            return a.first<b.first;
        });
        int i;
        for(i=0;i<n;){
            int numfalse=0,numtrue=0;
            int j;
            for(j=i;j<n&&arr[j].first==arr[i].first;++j){
                if(arr[j].second)++numtrue;
                else ++numfalse;
            }
            int expfalse=(j+1)/2-(i+1)/2,exptrue=j/2-i/2;
            if(numfalse!=expfalse||numtrue!=exptrue){
                break;
            }
            i=j;
        }
        if(i<n){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}