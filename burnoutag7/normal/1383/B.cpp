#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int cnt[50];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=30;j>=0;j--){
                cnt[j]+=a[i]>>j&1;
            }
        }
        bool win=0,lose=0;
        for(int j=30;j>=0;j--){
            if(cnt[j]&1){
                if((cnt[j]&3)==3&&n-cnt[j]&1^1)lose=1;
                else win=1;
                break;
            }
        }
        if(win)cout<<"WIN\n";
        if(lose)cout<<"LOSE\n";
        if(!win&&!lose)cout<<"DRAW\n";
    }

    return 0;
}