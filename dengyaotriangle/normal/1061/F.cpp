#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=1505;

int n,k,d=0;
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

int main(){
    cin>>n>>k;
    int ck=1,cn=n;
    while(1){
        d++;
        cn-=ck;
        ck*=k;
        if(cn==0)break;
    }
    int trg=d*2-1;
    while(1){
        int u=rng()%n+1,v=rng()%n+1;
        int cnt=0;
        vector<int> pth;
        for(int i=1;i<=n;i++){
            cout<<"? "<<u<<' '<<i<<' '<<v<<endl;
            fflush(stdout);
            char res[5];
            cin>>res;
            if(res[0]=='Y'){
                cnt++;
                pth.push_back(i);
            }
        }
        if(cnt==trg){
            for(int i=0;i<cnt;i++){
                int c1=0;
                for(int j=0;j<cnt;j++){
                    cout<<"? "<<u<<' '<<pth[j]<<' '<<pth[i]<<endl;
                    fflush(stdout);
                    char res[5];
                    cin>>res;
                    if(res[0]=='Y')c1++;
                }
                if(c1==d){
                    cout<<"! "<<pth[i]<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}