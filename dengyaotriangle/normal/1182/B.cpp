#include<bits/stdc++.h>

using namespace std;

const int maxn=505;
//lmyakioi
bool a[maxn][maxn];
int hl[maxn],hw[maxn];
int cl,cw;
int cn2=1,tot;
int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char _[maxn];
        cin>>(_+1);
        for(int j=1;j<=m;j++){
            a[i][j]=(_[j]=='*');
            if(a[i][j])tot++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]){
                hl[i]++;
                hw[j]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(hl[i]>1){
            if(cl){
                cout<<"NO";
                return 0;
            }
            cl=i;
        }
    }
    for(int i=1;i<=m;i++){
        if(hw[i]>1){
            if(cw){
                cout<<"NO";
                return 0;
            }
            cw=i;
        }
    }
    if(!cw||!cl){
        cout<<"NO";
        return 0;
    }
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    for(int i=0;i<4;i++){
        int cx=cl,cy=cw;
        if(!a[cx][cy]){
            cout<<"NO";
            return 0;
        }
        bool gt=0,ok=1;
        int cnt=0;
        while(cx>=1&&cy>=1&&cx<=n&&cy<=m){
            cx+=dx[i];
            cy+=dy[i];
            if(!a[cx][cy]){
                gt=1;
            }else{
                if(gt)ok=0;
                else cnt++;
            }
            
        }
        if(cnt<1){
            cout<<"NO";
            return 0;
        }
        if(!ok){
            cout<<"NO";
            return 0;
        }
        cn2+=cnt;
    }
    if(cn2!=tot){
        cout<<"NO";
    }else    cout<<"YES";
    return 0;
}