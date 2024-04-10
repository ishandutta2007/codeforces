#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        int score[2];
        score[0]=0,score[1]=0;
        int minkick=10;
        int left[2];
        left[0]=5,left[1]=5;
        for(int i=0;i<10;i++){
            if(score[0]+left[0]<score[1]){
                minkick=min(minkick,i);
                break;
            }
            if(score[1]+left[1]<score[0]){
                minkick=min(minkick,i);
                break;
            }
            left[i%2]--;
            if(a[i]=='1')score[i%2]++;
            else if(a[i]=='?'&&i%2==0)score[i%2]++;
        }
        score[0]=0,score[1]=0;
        left[0]=5,left[1]=5;
        for(int i=0;i<10;i++){
            if(score[0]+left[0]<score[1]){
                minkick=min(minkick,i);
                break;
            }
            if(score[1]+left[1]<score[0]){
                minkick=min(minkick,i);
                break;
            }
            left[i%2]--;
            if(a[i]=='1')score[i%2]++;
            else if(a[i]=='?'&&i%2==1)score[i%2]++;
        }
        printf("%d\n",minkick);
    }
    return 0;
}