#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
bool col[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int lastfig=-1;
        int firstfig=0;
        int a;
        int cnt=0;
        int ree=0;
        for(int i=1;i<=n;i++){
            cin>>a;
            if(lastfig==-1)firstfig=a;
            if(a==lastfig){
                col[i]=col[i-1];
                ree++;
            }
            else{
                col[i]=!col[i-1];
                cnt++;
            }
            lastfig=a;
        }
        cnt=min(cnt,2);
        bool change=false;
        if(firstfig!=lastfig){
            if(col[1]==col[n]){
                if(!ree)cnt++;
                else change=true;
            }
        }
        printf("%d\n",cnt);
        bool flip=false;
        for(int i=1;i<=n;i++){
            if(change&&col[i]==col[i-1]){
                flip=true;
                change=false;
            }
            if(flip)col[i]=!col[i];
            if(i==n&&cnt==3){
                printf("3 ");
            }
            else{
                if(cnt==1)printf("1 ");
                else printf("%d ",(int)col[i]+1);
            }
        }
        printf("\n");
    }
    return 0;
}