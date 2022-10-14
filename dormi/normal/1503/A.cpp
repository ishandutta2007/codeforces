#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
bool fliplocs[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a;
        cin>>a;
        if(a[0]=='0'||a[sz(a)-1]=='0'){
            printf("NO\n");
            continue;
        }
        a[0]='(',a[sz(a)-1]=')';
        int onecnt=0,total=0,pre=0;
        for(int i=1;i<sz(a)-1;i++){
            if(a[i]=='0'){
                fliplocs[i]=true;
                a[i]=(pre==0?')':'(');
                pre=!pre;
                total++;
            }
            else onecnt++,fliplocs[i]=false;
        }
        if(total%2==1){
            printf("NO\n");
            continue;
        }
        int half=onecnt/2;
        for(int i=1;i<sz(a)-1;i++){
            if(a[i]=='1'){
                if(onecnt<=half)a[i]=')';
                else a[i]='(';
                onecnt--;
            }
        }
        printf("YES\n");
        for(auto x:a)printf("%c",x);
        for(int i=1;i<sz(a)-1;i++){
            if(fliplocs[i]){
                if(a[i]==')')a[i]='(';
                else a[i]=')';
            }
        }
        printf("\n");
        for(auto x:a)printf("%c",x);
        printf("\n");
    }
    return 0;
}